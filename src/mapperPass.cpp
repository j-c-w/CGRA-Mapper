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
#include "Options.h"
#include "MapResult.h"
#include "MapAlgorithms.h"

using namespace llvm;
using namespace std;

namespace {

  struct mapperPass : public FunctionPass {

  public:
    static char ID;
    mapperPass() : FunctionPass(ID) {}

    void getAnalysisUsage(AnalysisUsage &AU) const override {
      AU.addRequired<LoopInfoWrapperPass>();
      AU.addPreserved<LoopInfoWrapperPass>();
      AU.setPreservesAll();
    }

    bool runOnFunction(Function &t_F) override {
	  Options *options = setupOptions();

      // Read the parameter JSON file.
	  if (options->Params == "") {
		  errs() << "No params file passed, uding default.";
		  options->Params = "param.json";
	  }
    Parameters *params = new Parameters(options->Params);

      // Check existance.
      if (params->functionWithLoop->find(t_F.getName().str()) == params->functionWithLoop->end()) {
        errs()<<"[function \'"<<t_F.getName()<<"\' is not in our target list]\n";
		// OK, so thi swas meant to return fasle, because in theoyr you
		// need to specify which loop to use.  I'm not going to do that, and
		// just assume one loop in the body, (as is commented elsewhere in this
		// code), because it's a bit simpler :)
        // return false;
      }
      errs() << "==================================\n";
      errs()<<"[function \'"<<t_F.getName()<<"\' is one of our targets]\n";

      list<Loop*>* targetLoops = getTargetLoops(t_F, params->functionWithLoop, params->targetNested);
      // TODO: will make a list of patterns/tiles to illustrate how the
      //       heterogeneity is
      DFG* dfg = params->getDFG(t_F, targetLoops);
      if (options->DumpFeatures.compare("") != 0) {
        errs() << "Dumping DFG Features to " << options->DumpFeatures << "\n";
        dfg->dumpFeatures(options->DumpFeatures);
        errs() << "Done Dumping DFG Features\n";
      }
      /* if (options.DumpDFG) { */
      /*   dfg->dumpAsJson("DFG.json"); */
      /* } */
      CGRA* cgra = params->getCGRA(options);
      cgra->setRegConstraint(params->regConstraint);
      cgra->setCtrlMemConstraint(params->ctrlMemConstraint);
      cgra->setBypassConstraint(params->bypassConstraint);

        // Generate the DFG dot file.
        errs() << "==================================\n";
        errs() << "[generate dot for DFG]\n";
        dfg->generateDot(&t_F, params->isTrimmedDemo);


      runMapping(cgra, dfg, params, options);

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
RegisterPass<mapperPass> mapPass("mapperPass", "DFG Pass Analyse", false, false);
