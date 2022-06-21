#include <llvm/Support/CommandLine.h>
#include <fstream>
#include "json.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Options.h"
#include <map>
#include "CGRA.h"
#include "DFG.h"
#include <list>

using namespace llvm;
using json = nlohmann::json;

cl::opt<bool> BuildCGRA("build", cl::desc("Build the CGRA from the code rather than mapping to it."));

// op mode flags.
cl::opt<bool> UseRewriter("use-rewriter", cl::desc("Use the simple rewriter"));
cl::opt<bool> UseEGraphs("use-egraphs", cl::desc("Use the egraphs-based rewriter"));

// Debug flags
cl::opt<bool> PrintMappingFailures("print-mapping-failures", cl::desc("Print the operations where mapping fails"));
cl::opt<bool> DebugMappingLoop("debug-mapping-loop", cl::desc("Debug the mapping loop."));
cl::opt<bool> DebugRustConversion("debug-rust-conversion", cl::desc("Debug the egraphs interface on the C++ side"));
cl::opt<bool> LLVMDebugOperationMap ("debug-operation-map", cl::desc("Debug the node-by-node operation mapping"));
cl::opt<bool> PrintOperationCount("print-operation-count", cl::desc("Print the operation counts in the DFG for debugging rewrite rules"));

cl::opt<std::string> Params("params-file", cl::desc("Json file with the CGRA parameters"));

Options::Options () {}

// To be called after application has started.  Copies the command
// line results into global variables that can be accessed
// via Options.h
Options *setupOptions() {
	Options *opt = new Options();
	opt->BuildCGRA = BuildCGRA;

	opt->UseRewriter = UseRewriter;
	opt->UseEGraphs = UseEGraphs;

	opt->DebugOperationMap = LLVMDebugOperationMap;
	opt->DebugRustConversion = DebugRustConversion;
	opt->DebugMappingLoop = DebugMappingLoop;
	opt->PrintMappingFailures = PrintMappingFailures;
	opt->PrintOperationCount = PrintOperationCount;

	opt->Params = Params;

	return opt;
}

// CGRA mapper uses a json file for the CGRA description.
// Load the parameters from that.
Parameters::Parameters(std::string filename) {
      // Initializes input parameters.
      rows                      = 4;
      columns                  = 4;
      targetEntireFunction     = false;
      targetNested             = false;
      doCGRAMapping            = true;
      isStaticElasticCGRA      = false;
      isTrimmedDemo            = true;
      ctrlMemConstraint         = 200;
      bypassConstraint          = 4;
      regConstraint             = 8;
      precisionAware           = false;
      heterogeneity            = false;
      heuristicMapping         = true;
      execLatency = new map<string, int>();
      pipelinedOpt    = new list<string>();
      additionalFunc = new map<string, list<int>*>();
	  opmap = new map<int, map<int, list<OperationNumber>*>*>();

      // Set the target function and loop.
      functionWithLoop = new map<string, list<int>*>();
      addDefaultKernels(functionWithLoop);
	  ifstream i(filename);
	  
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
          cout << "Set exec latency\n";
        }
        cout << "Setting pipelined opts\n";
        json pipeOpt = param["optPipelined"];
        for (int i=0; i<pipeOpt.size(); ++i) {
          cout << "Starting to set pipe opt\n";
          cout << "Setting pipe opt " << pipeOpt[i] << "\n";
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

}

DFG* Parameters::getDFG(Function &t_F, list<Loop *>* targetLoops) {
	DFG *dfg = new DFG(&t_F, targetLoops, targetEntireFunction, precisionAware,
					   heterogeneity, execLatency, pipelinedOpt);
	return dfg;
}

CGRA* Parameters::getCGRA(Options *opts) {
	CGRA *cgra = new CGRA(rows, columns, heterogeneity, additionalFunc, opmap, opts->BuildCGRA);
	return cgra;
}

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

