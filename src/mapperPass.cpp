/*
 * ======================================================================
 * mapperPass.cpp
 * ======================================================================
 * Mapper pass implementation.
 *
 * Author : Cheng Tan
 *   Date : Aug 16, 2021
 */

#include <llvm/IR/Function.h>
#include <llvm/Pass.h>
#include <llvm/Analysis/LoopInfo.h>
#include <llvm/Analysis/LoopIterator.h>
#include <llvm/Support/CommandLine.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include "json.hpp"
#include "Mapper.h"
#include "OperationMap.h"
#include "Rewriter.h"
#include "RustConversion.h"


using namespace llvm;
using namespace std;
using json = nlohmann::json;

void addDefaultKernels(map<string, list<int>*>*);

cl::opt<bool> BuildCGRA("build", cl::desc("Build the CGRA from the code rather than mapping to it."));

// op mode flags.
cl::opt<bool> UseRewriter("rewriter", cl::desc("Use the simple rewriter"));
cl::opt<bool> UseEGraphs("use-egraphs", cl::desc("Use the egraphs-based rewriter"));

// Debug flags
cl::opt<bool> PrintMappingFailures("print-mapping-failures", cl::desc("Print the operations where mapping fails"));
cl::opt<bool> DebugMappingLoop("debug-mapping-loop", cl::desc("Debug the mapping loop."));
cl::opt<bool> DebugRustConversion("debug-rust-conversion", cl::desc("Debug the egraphs interface on the C++ side"));


namespace {

  struct mapperPass : public FunctionPass {

  public:
    static char ID;
    Mapper* mapper;
    mapperPass() : FunctionPass(ID) {}

    void getAnalysisUsage(AnalysisUsage &AU) const override {
      AU.addRequired<LoopInfoWrapperPass>();
      AU.addPreserved<LoopInfoWrapperPass>();
      AU.setPreservesAll();
    }

    bool runOnFunction(Function &t_F) override {
      // Initializes input parameters.
      int rows                      = 4;
      int columns                   = 4;
      bool targetEntireFunction     = false;
      bool targetNested             = false;
      bool doCGRAMapping            = true;
      bool isStaticElasticCGRA      = false;
      bool isTrimmedDemo            = true;
      int ctrlMemConstraint         = 200;
      int bypassConstraint          = 4;
      int regConstraint             = 8;
      bool precisionAware           = false;
      bool heterogeneity            = false;
      bool heuristicMapping         = true;
      map<string, int>* execLatency = new map<string, int>();
      list<string>* pipelinedOpt    = new list<string>();
      map<string, list<int>*>* additionalFunc = new map<string, list<int>*>();
	  map<int, map<int, list<OperationNumber>*>*>* opmap = new map<int, map<int, list<OperationNumber>*>*>();

      // Set the target function and loop.
      map<string, list<int>*>* functionWithLoop = new map<string, list<int>*>();
      addDefaultKernels(functionWithLoop);

      // Read the parameter JSON file.
      ifstream i("./param.json");
      if (!i.good()) {

        cout<< "=============================================================\n";
        cout<<"\033[0;31mPlease provide a valid <param.json> in the current directory."<<endl;
        cout<<"A set of default parameters is leveraged.\033[0m"<<endl;
        cout<< "=============================================================\n";
      } else {
        json param;
        i >> param;
 
        (*functionWithLoop)[param["kernel"]] = new list<int>();
        json loops = param["targetLoopsID"];
        for (int i=0; i<loops.size(); ++i) {
          // cout<<"add index "<<loops[i]<<endl;
          (*functionWithLoop)[param["kernel"]]->push_back(loops[i]);
        }

		// load ops.
	  for (int row = 0; row < rows; row ++) {
		  auto submap = new map<int, list<OperationNumber>*>();
		  for (int col = 0; col < columns; col ++) {
			  list<OperationNumber> *opslist = new list<OperationNumber>();
			  /* cout << "Adding row " << endl; */
			  /* cout << std::to_string(row) << endl; */
			  /* cout << std::to_string(col) << endl; */
			  /* cout << param["operations"][std::to_string(row)] << endl; */
			  for (auto item : param["operations"][std::to_string(row)][std::to_string(col)].items()) {
				  opslist->push_front(item.value());
				  std::cout << item.value() << "added" << endl;
			  }
			  ( *submap )[col] = opslist;
		  }

		  (*opmap)[row] = submap;
	  }


        // Configuration for customizable CGRA.
        rows                  = param["row"];
        columns               = param["column"];
        targetEntireFunction  = param["targetFunction"];
        targetNested          = param["targetNested"];
        doCGRAMapping         = param["doCGRAMapping"];
        isStaticElasticCGRA   = param["isStaticElasticCGRA"];
        isTrimmedDemo         = param["isTrimmedDemo"];
        ctrlMemConstraint     = param["ctrlMemConstraint"];
        bypassConstraint      = param["bypassConstraint"];
        regConstraint         = param["regConstraint"];
        precisionAware        = param["precisionAware"];
        heterogeneity         = param["heterogeneity"];
        heuristicMapping      = param["heuristicMapping"];
        cout<<"Initialize opt latency for DFG nodes: "<<endl;
        for (auto& opt : param["optLatency"].items()) {
          cout<<opt.key()<<" : "<<opt.value()<<endl;
          (*execLatency)[opt.key()] = opt.value();
        }
        json pipeOpt = param["optPipelined"];
        for (int i=0; i<pipeOpt.size(); ++i) {
          pipelinedOpt->push_back(pipeOpt[i]);
        }
        cout<<"Initialize additional functionality on CGRA nodes: "<<endl;
        for (auto& opt : param["additionalFunc"].items()) {
          (*additionalFunc)[opt.key()] = new list<int>();
          cout<<opt.key()<<" : "<<opt.value()<<": ";
          for (int i=0; i<opt.value().size(); ++i) {
            (*additionalFunc)[opt.key()]->push_back(opt.value()[i]);
            cout<<opt.value()[i]<<" ";
          }
          cout<<endl;
        }
      }

      // Check existance.
      if (functionWithLoop->find(t_F.getName().str()) == functionWithLoop->end()) {
        errs()<<"[function \'"<<t_F.getName()<<"\' is not in our target list]\n";
		// OK, so thi swas meant to return fasle, because in theoyr you
		// need to specify which loop to use.  I'm not going to do that, and
		// just assume one loop in the body, (as is commented elsewhere in this
		// code), because it's a bit simpler :)
        // return false;
      }
      errs() << "==================================\n";
      errs()<<"[function \'"<<t_F.getName()<<"\' is one of our targets]\n";

      list<Loop*>* targetLoops = getTargetLoops(t_F, functionWithLoop, targetNested);
      // TODO: will make a list of patterns/tiles to illustrate how the
      //       heterogeneity is
      DFG* dfg = new DFG(&t_F, targetLoops, targetEntireFunction, precisionAware,
                         heterogeneity, execLatency, pipelinedOpt);
      CGRA* cgra = new CGRA(rows, columns, heterogeneity, additionalFunc, opmap, BuildCGRA);
      cgra->setRegConstraint(regConstraint);
      cgra->setCtrlMemConstraint(ctrlMemConstraint);
      cgra->setBypassConstraint(bypassConstraint);
      mapper = new Mapper();

      // Show the count of different opcodes (IRs).
      errs() << "==================================\n";
      errs() << "[show opcode count]\n";
      dfg->showOpcodeDistribution();

      // Generate the DFG dot file.
      errs() << "==================================\n";
      errs() << "[generate dot for DFG]\n";
      dfg->generateDot(&t_F, isTrimmedDemo);

      // Generate the DFG dot file.
      errs() << "==================================\n";
      errs() << "[generate JSON for DFG]\n";
      dfg->generateJSON();

      // Initialize the II.
      int ResMII = mapper->getResMII(dfg, cgra);
      errs() << "==================================\n";
      errs() << "[ResMII: " << ResMII << "]\n";
      int RecMII = mapper->getRecMII(dfg);
      errs() << "==================================\n";
      errs() << "[RecMII: " << RecMII << "]\n";
      int II = ResMII;
      if(II < RecMII)
        II = RecMII;

      if (!doCGRAMapping) {
        errs() << "==================================\n";
        return false;
      }
      // Heuristic algorithm (hill climbing) to get a valid mapping within
      // a acceptable II.
	  // Jackson's Code Starts Here:
	  // Get the winning DFG.
	  DFG *winning_dfg;

	  list<DFG*> *generated_dfgs;
	  if (UseRewriter) {
		  generated_dfgs = rewrite_for_CGRA(cgra, dfg);
	  } else if (UseEGraphs) {
		  generated_dfgs = rewrite_with_egraphs(cgra, dfg, DebugRustConversion);
	  } else {
		  // if we aren't using the rewriter, just create
		  // a singleton list.
		  generated_dfgs = new list<DFG *>;
		  generated_dfgs->push_back(dfg);
	  }

	  int min_II = -1;
	  int dfg_no = 0;
	  for (DFG *dfg : *generated_dfgs) {
		  if (DebugMappingLoop) {
			  cout << "Starting mapper for new DFG (Number " << ++dfg_no << ")" << endl;
			  cout << "DFG is : " << dfg->asString() << endl;
		  }
		  int this_II = mapper->heuristicMap(cgra, dfg, II, isStaticElasticCGRA, PrintMappingFailures);

		  if ((this_II < min_II || min_II < 0) && this_II > 0) {
			  min_II = this_II;
			  winning_dfg = dfg;
		  }
		  if (DebugMappingLoop) {
			  cout << "DFG Number " << dfg_no << " had II " << this_II << endl;
		  }
	  }
	  II = min_II;
	  /// end jackson's code.

      // Partially exhaustive search to try to map the DFG onto
      // the static elastic CGRA.

      // Show the mapping and routing results with JSON output.
      if (II == -1)
        errs() << "[fail]\n";
      else {
        mapper->showSchedule(cgra, winning_dfg, II, isStaticElasticCGRA);
        errs() << "==================================\n";
        errs() << "[success]\n";
        errs() << "==================================\n";
        mapper->generateJSON(cgra, winning_dfg, II, isStaticElasticCGRA);
        errs() << "[Output Json]\n";
      }
      errs() << "==================================\n";

      return false;
    }

    /*
     * Add the loops of each kernel. Target nested-loops if it is indicated.
     */
    list<Loop*>* getTargetLoops(Function& t_F, map<string, list<int>*>* t_functionWithLoop, bool t_targetNested) {
		// So, this originally relied on a function-dependent list map thing at the bottom
		// of this file.  But that seemed silly since they're all 0s anway.  So just assume we got
		// a list iwth zero from that.
      int targetLoopID = 0;
      list<Loop*>* targetLoops = new list<Loop*>();
      // Since the ordering of the target loop id could be random, I use O(n^2) to search the target loop.
        LoopInfo &LI = getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
        int tempLoopID = 0;
        Loop* current_loop = NULL;
        for(LoopInfo::iterator loopItr=LI.begin();
            loopItr!= LI.end(); ++loopItr) {
          // targetLoops->push_back(*loopItr);
          current_loop = *loopItr;
          if (tempLoopID == targetLoopID) {
            // Targets innermost loop if the param targetNested is not set.
            if (!t_targetNested) {
              while (!current_loop->getSubLoops().empty()) {
                errs()<<"[explore] nested loop ... subloop size: "<<current_loop->getSubLoops().size()<<"\n";
                // TODO: might change '0' to a reasonable index
                current_loop = current_loop->getSubLoops()[0];
              }
            }
            targetLoops->push_back(current_loop);
            errs()<<"*** reach target loop ID: "<<tempLoopID<<"\n";
            break;
          }
          ++tempLoopID;
        }
        if (targetLoops->size() == 0) {
          errs()<<"... no loop detected in the target kernel ...\n";
        }
      errs()<<"... done detected loops.size(): "<<targetLoops->size()<<"\n";
      return targetLoops;
    }
  };
}

char mapperPass::ID = 0;
static RegisterPass<mapperPass> X("mapperPass", "DFG Pass Analyse", false, false);

/*
 * Add the kernel names of some popular applications.
 * Assume each kernel contains single loop.
 */
void addDefaultKernels(map<string, list<int>*>* t_functionWithLoop) {

  (*t_functionWithLoop)["_Z12ARENA_kerneliii"] = new list<int>();
  (*t_functionWithLoop)["_Z12ARENA_kerneliii"]->push_back(0);
  (*t_functionWithLoop)["_Z4spmviiPiS_S_"] = new list<int>();
  (*t_functionWithLoop)["_Z4spmviiPiS_S_"]->push_back(0);
  (*t_functionWithLoop)["_Z4spmvPiii"] = new list<int>();
  (*t_functionWithLoop)["_Z4spmvPiii"]->push_back(0);
  (*t_functionWithLoop)["adpcm_coder"] = new list<int>();
  (*t_functionWithLoop)["adpcm_coder"]->push_back(0);
  (*t_functionWithLoop)["adpcm_decoder"] = new list<int>();
  (*t_functionWithLoop)["adpcm_decoder"]->push_back(0);
  (*t_functionWithLoop)["kernel_gemm"] = new list<int>();
  (*t_functionWithLoop)["kernel_gemm"]->push_back(0);
  (*t_functionWithLoop)["kernel"] = new list<int>();
  (*t_functionWithLoop)["kernel"]->push_back(0);
  (*t_functionWithLoop)["_Z6kernelPfS_S_"] = new list<int>();
  (*t_functionWithLoop)["_Z6kernelPfS_S_"]->push_back(0);
  (*t_functionWithLoop)["_Z6kerneliPPiS_S_S_"] = new list<int>();
  (*t_functionWithLoop)["_Z6kerneliPPiS_S_S_"]->push_back(0);
  (*t_functionWithLoop)["_Z6kernelPPii"] = new list<int>();
  (*t_functionWithLoop)["_Z6kernelPPii"]->push_back(0);
  (*t_functionWithLoop)["_Z6kernelP7RGBType"] = new list<int>();
  (*t_functionWithLoop)["_Z6kernelP7RGBType"]->push_back(0);
  (*t_functionWithLoop)["_Z6kernelP7RGBTypePi"] = new list<int>();
  (*t_functionWithLoop)["_Z6kernelP7RGBTypePi"]->push_back(0);
  (*t_functionWithLoop)["_Z6kernelP7RGBTypeP4Vect"] = new list<int>();
  (*t_functionWithLoop)["_Z6kernelP7RGBTypeP4Vect"]->push_back(0);
  (*t_functionWithLoop)["fir"] = new list<int>();
  (*t_functionWithLoop)["fir"]->push_back(0);
  (*t_functionWithLoop)["spmv"] = new list<int>();
  (*t_functionWithLoop)["spmv"]->push_back(0);
  // (*functionWithLoop)["fir"].push_back(1);
  (*t_functionWithLoop)["latnrm"] = new list<int>();
  (*t_functionWithLoop)["latnrm"]->push_back(1);
  (*t_functionWithLoop)["fft"] = new list<int>();
  (*t_functionWithLoop)["fft"]->push_back(0);
  (*t_functionWithLoop)["BF_encrypt"] = new list<int>();
  (*t_functionWithLoop)["BF_encrypt"]->push_back(0);
  (*t_functionWithLoop)["susan_smoothing"] = new list<int>();
  (*t_functionWithLoop)["susan_smoothing"]->push_back(0);

  (*t_functionWithLoop)["_Z9LUPSolve0PPdPiS_iS_"] = new list<int>();
  (*t_functionWithLoop)["_Z9LUPSolve0PPdPiS_iS_"]->push_back(0);

  // For LU:
  // init
  (*t_functionWithLoop)["_Z6kernelPPdidPi"] = new list<int>();
  (*t_functionWithLoop)["_Z6kernelPPdidPi"]->push_back(0);

  // solver0 & solver1
  (*t_functionWithLoop)["_Z6kernelPPdPiS_iS_"] = new list<int>();
  (*t_functionWithLoop)["_Z6kernelPPdPiS_iS_"]->push_back(0);

  // determinant
  (*t_functionWithLoop)["_Z6kernelPPdPii"] = new list<int>();
  (*t_functionWithLoop)["_Z6kernelPPdPii"]->push_back(0);

  // invert
  (*t_functionWithLoop)["_Z6kernelPPdPiiS0_"] = new list<int>();
  (*t_functionWithLoop)["_Z6kernelPPdPiiS0_"]->push_back(0);

  // nested
  // (*t_functionWithLoop)["_Z6kernelPfS_S_"] = new list<int>();
  // (*t_functionWithLoop)["_Z6kernelPfS_S_"]->push_back(0);
}


