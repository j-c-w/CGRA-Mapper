#include <fstream>
#include "json.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <stdlib.h>
#include "Options.h"
#include <map>
#include "CGRA.h"
#include "DFG.h"
#include <list>
#include <tclap/CmdLine.h>
#include "RustTypes.h"

using namespace llvm;
using json = nlohmann::json;


// Trouble figuring out how to link these defs in the standalone version
// that uses the TClap processing anyway.
// Given that these rely on opt --- I'm not 100% sure it's even possible
// to link them.
#ifndef DISABLE_LLVM_CMDLINE
#include <llvm/Support/CommandLine.h>
#warning "Adding LLVm options"
// Due to having two different entry points, we have to maintain two differnet
// sets of options (PITA).  LLVM opt options:
cl::opt<bool> BuildCGRA("build", cl::desc("Build the CGRA from the code rather than mapping to it."));
cl::opt<bool> DumpDFG("dump-dfg", cl::desc("Dump the DFG to a file (DFG.json) for use with other tools. UNIMPLEMENTED"));
cl::opt<bool> SkipBuild("skip-build", cl::desc("Skip building for the CGRA. (for use with dumping functions) "));
cl::opt<std::string> DumpFeatures("features", cl::desc("Dump the of the DFG to a file (specified as arg to flag) for use with other tools. "));
cl::opt<std::string> DumpFrequencies("frequencies", cl::desc("Dump the operation frequencies into a file (specified as arg to flag) for use with other tools."));
cl::opt<bool> DumpEGraphs("dump-egraph", cl::desc("Dump the egraph before and after rewriting"));

cl::opt<std::string> RuleFile("rule-file", cl::desc("A json file with the specific rules to use for this CGRA"));

// op mode flags.
cl::opt<bool> UseRewriter("use-rewriter", cl::desc("Use the simple rewriter"));
cl::opt<bool> UseEGraphs("use-egraphs", cl::desc("Use the egraphs-based rewriter"));
cl::opt<bool> UseGreedy("use-greedy", cl::desc("Use greedy rewriter"));

// Debug flags
cl::opt<bool> PrintMappingFailures("print-mapping-failures", cl::desc("Print the operations where mapping fails"));
cl::opt<bool> DebugMappingLoop("debug-mapping-loop", cl::desc("Debug the mapping loop."));
cl::opt<bool> DebugRustConversion("debug-rust-conversion", cl::desc("Debug the egraphs interface on the C++ side"));
cl::opt<bool> DebugBreakCycles("debug-break-cycles", cl::desc("Debug break cycles"));
cl::opt<bool> LLVMDebugOperationMap ("debug-operation-map", cl::desc("Debug the node-by-node operation mapping"));
cl::opt<bool> PrintOperationCount("print-operation-count", cl::desc("Print the operation counts in the DFG for debugging rewrite rules"));
cl::opt<bool> PrintUsedRules("print-used-rules", cl::desc("Print the number of used rules"));
cl::opt<int> MaxII("max-ii", cl::desc("Max II to scan up to"), cl::init(50));

cl::opt<std::string> Params("params-file", cl::desc("Json file with the CGRA parameters"));
cl::list<std::string> RulesetsOpt("ruleset", cl::desc("Rulesets to use: valid options are: int, fp, boolean, stochastic, gcc (default is gcc, gcc = int ruleset + fp ruleset)"));
cl::opt<std::string> EGraphMode("egraph-mode", cl::desc("Rewrite mode used by EGraphs.  Options are: binary, frequency."), cl::init("binary"));

#endif

bool is_valid_ruleset(std::string rname) {
  return
    (!rname.compare("fp")) ||
    (!rname.compare("int")) ||
    (!rname.compare("boolean")) ||
    (!rname.compare("stochastic")) ||
    (!rname.compare("cannonicalize")) ||
    (!rname.compare("gcc"));
}

// Setup the options for non-llvm toolchain.
TClapOptions *setupOptionsTClap(int argc, char **argv) {
TCLAP::CmdLine cmd("Tool to schedule a DFG Json file onto a CGRA");
  TCLAP::UnlabeledValueArg<std::string> dfg("DFGJson", "The JSON file with the DFG in it", true, "", "string");
  TCLAP::UnlabeledValueArg<std::string> cgra("CGRAJson", "The params.json file that describes the CGRA", true, "", "string");
  TCLAP::ValueArg<std::string> ruleFile("", "rule-file", "A json file with the specific rules to use for this CGRA", false, "", "string");

  TCLAP::SwitchArg build_cgra("b", "build","Build the cgra rather than targeting a fixed one", cmd, false);
  TCLAP::SwitchArg use_egraphs("e", "use-egraphs", "Use the egraph rewriter", cmd, false);
  TCLAP::SwitchArg use_rewriter("r", "use-rewriter", "Use the standard rewriter", cmd, false);
  TCLAP::SwitchArg use_greedy("g", "use-greedy", "Use the greedy rewriter", cmd, false);
  TCLAP::SwitchArg dump_egraph("d", "dump-egraph", "Dump the egraph before and after rewriting", cmd, false);

  // TCLAP optional string flag

  TCLAP::SwitchArg debug_mapping_loop("", "debug-mapping-loop", "Debug the mapping loop", cmd, false);
  TCLAP::SwitchArg print_mapping_failures("", "print-mapping-failures", "Debugg mapping failures", cmd, false);
  TCLAP::SwitchArg skip_build("", "skip-build", "only do dump", cmd, false);

  TCLAP::MultiArg<std::string> trulesets("s", "ruleset", "Rulesets (valid sets are int, fp, boolean, gcc (gcc = int + fp).  Default is gcc", false, "ruleset", cmd);

  try {
    cmd.add(dfg);
    cmd.add(cgra);

    cmd.parse(argc, argv);
  } catch (TCLAP::ArgException &e) {
      std::cerr << "Error: " << e.error() << " with arg " << e.argId() << std::endl;
  }
  Options *opt = new Options();
  opt->BuildCGRA = build_cgra;
  opt->DumpDFG = false;
  opt->SkipBuild = skip_build;
  opt->DumpFeatures = "";
  opt->DumpFrequencies = "";
  opt->DumpEGraphs = dump_egraph;
  opt->RuleFile = ruleFile;

  opt->UseEGraphs = use_egraphs;
  opt->UseRewriter = use_rewriter;
  opt->UseGreedy = use_greedy;

  // TODO --- Support this.
  opt->DebugMappingLoop = debug_mapping_loop;
  opt->DebugRustConversion = false;
  opt->DebugOperationMap = false;
  opt->DebugBreakCycles = false;
  opt->PrintMappingFailures = print_mapping_failures;
  opt->PrintOperationCount = false;
  opt->PrintUsedRules = false;
  opt->MaxII = 50;

  opt->Params = cgra.getValue();
  opt->rulesets = list<std::string>();

  for (std::string value : trulesets.getValue()) {
    if (!value.compare("gcc")) {
      opt->rulesets.push_back("int");
      opt->rulesets.push_back("fp");
    } else if (is_valid_ruleset(value)) {
      opt->rulesets.push_back(value);
    } else {
      throw invalid_argument("Invalid ruleset " + value);
    }
  }

  TClapOptions *toptions = new TClapOptions();
  toptions->options = opt;
  toptions->dfg_file = dfg.getValue();
  return toptions;
}

Options::Options () {}
TClapOptions::TClapOptions() {}

// Ruleset names for printing.
std::string Options::getRulesetNames() {
  std::string result;
  for (std::string nm : rulesets) {
    result += nm + ", ";
  }

  return result;
}

Rulesets Options::getRulesets() {
  int size = rulesets.size();
  const char **names = (const char**) malloc(sizeof(char*) * size);

  list<std::string>::iterator nms = rulesets.begin();
  for (int i = 0; i < size; i ++) {
    names[i] = nms->c_str();
    nms ++;
  }

  Rulesets rset;
  rset.names = names;
  rset.num_names = size;
  return rset;
}

// To be called after application has started.  Copies the command
// line results into global variables that can be accessed
// via Options.h
Options *setupOptions() {
	Options *opt = new Options();
  #ifndef DISABLE_LLVM_CMDLINE
  opt->BuildCGRA = BuildCGRA;
  opt->DumpDFG = DumpDFG;
  opt->SkipBuild = SkipBuild;
  opt->DumpFeatures = DumpFeatures;
  opt->DumpFrequencies = DumpFrequencies;
  opt->DumpEGraphs = DumpEGraphs;
  opt->RuleFile = RuleFile;

	opt->UseRewriter = UseRewriter;
	opt->UseEGraphs = UseEGraphs;
  opt->UseGreedy = UseGreedy;

	opt->DebugOperationMap = LLVMDebugOperationMap;
	opt->DebugRustConversion = DebugRustConversion;
  opt->DebugBreakCycles = DebugBreakCycles;
	opt->DebugMappingLoop = DebugMappingLoop;
	opt->PrintMappingFailures = PrintMappingFailures;
	opt->PrintOperationCount = PrintOperationCount;
  opt->PrintUsedRules = PrintUsedRules;

  opt->MaxII = MaxII;

	opt->Params = Params;
  opt->rulesets = list<std::string>();
  opt->EGraphMode = EGraphMode;

  if (opt->EGraphMode.compare("binary") && opt->EGraphMode.compare("frequency")) {
	  throw invalid_argument("Invlaid mode " + opt->EGraphMode);
  }
  for (std::string rnam : RulesetsOpt) {
    if (!rnam.compare("gcc")) {
      opt->rulesets.push_back("fp");
      opt->rulesets.push_back("int");
    } else if (is_valid_ruleset(rnam)) {
      opt->rulesets.push_back(rnam);
    } else {
      // Invalid rulset
      std::cout << "Invalid Ruleset " << rnam << " Requested. " << std::endl;
      throw std::invalid_argument("Invalid ruleset");
    }
  }
  if (opt->rulesets.size() == 0) {
    opt->rulesets.push_back("fp");
    opt->rulesets.push_back("int");
  }
  #endif

	return opt;
}

// CGRA mapper uses a json file for the CGRA description.
// Load the parameters from that.
Parameters::Parameters(std::string filename) {
      // Initializes input parameters.
      rows                      = 4;
      columns                  = 4;
      homogenousPEs = false; // Do PEs support all operations (alternative to the operation map)
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
 
        (*functionWithLoop)[param["kernel"]] = new list<int>();
        json loops = param["targetLoopsID"];
        for (int i=0; i<loops.size(); ++i) {
          // cout<<"add index "<<loops[i]<<endl;
          (*functionWithLoop)[param["kernel"]]->push_back(loops[i]);
        }

    if (param.contains("homogenousPEs")) {
      cout << "Homogenous PEs is set\n";
      homogenousPEs = param["homogenousPEs"];
    } else {
      cout << "Homogenous PEs not set\n";
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
				  std::cout << item.value() << "added, at " << row << ", "  << col << endl;
			  }
			  ( *submap )[col] = opslist;
		  }

		  (*opmap)[row] = submap;
	  }



        // Configuration for customizable CGRA.
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
        cout << "Parameters loaded!\n";
      }
}

DFG* Parameters::getDFG(Function &t_F, list<Loop *>* targetLoops) {
	DFG *dfg = new DFG(&t_F, targetLoops, targetEntireFunction, precisionAware,
					   heterogeneity, execLatency, pipelinedOpt);
	return dfg;
}

CGRA* Parameters::getCGRA(Options *opts) {
	CGRA *cgra = new CGRA(opts, this);
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
