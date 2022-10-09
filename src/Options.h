#ifndef OPTIONS_H

// TODO -- These are broken --- want to figure out how to do this
// gobal thing.
#include <llvm/Support/CommandLine.h>
#include <llvm/IR/Function.h>
#include <llvm/Analysis/LoopInfo.h>

class DFG;
class CGRA;

#include<string>
#include <map>
#include <list>
#include "OperationMap.h"
#include "RustTypes.h"
using namespace std;
using namespace llvm;

class Options {
	public:
		Options();
		bool BuildCGRA;
		bool DumpDFG;
		bool SkipBuild;
		std::string DumpFeatures;
		std::string DumpFrequencies;

		bool UseRewriter;
		bool UseEGraphs;
		bool UseGreedy;

		bool DebugOperationMap;
		bool DebugRustConversion;
		bool DebugMappingLoop;
		bool DebugBreakCycles;
		bool PrintMappingFailures;
		bool PrintOperationCount;
		bool PrintUsedRules;
		
		std::string Params;
		list<std::string> rulesets;

		Rulesets getRulesets(); // Return the ruleset names in C form to be passed to rust.
		std::string getRulesetNames();
};

// Carries the normal options + the positional parameters that
// specify the input files.
class TClapOptions {
public:
TClapOptions();
	Options *options;
	std::string dfg_file;
};

// Various parameters should be setup in a single algorihtm.
class Parameters {
	public:
	int rows;
	int columns;
	// JCW: I didn't write this code, and it came with few comments,
	// so I don't actually know what most of these do.
	bool targetEntireFunction;
	bool targetNested;
	bool doCGRAMapping;
	bool isStaticElasticCGRA;
	bool isTrimmedDemo;
	int ctrlMemConstraint;
	int bypassConstraint;
	int regConstraint;
	bool precisionAware;
	bool heterogeneity; // (Controls where you can do fused ops it seems, but it also seems to default to allowing everything to do fused ops)
	bool heuristicMapping;
	bool homogenousPEs; // I added this --- it's different from heterogeneity, which refers
	// mostly to loads and stores, this refers to finer-grained operations.
	// When set to true, the opmap is ignored.
	map<string, int> *execLatency;
	list<string> *pipelinedOpt;
	map<string, list<int> *> *additionalFunc;
	map<int, map<int, list<OperationNumber> *> *> *opmap;
	// Set the target function and loop.
	map<string, list<int> *> *functionWithLoop;

	Parameters(std::string paramfilename);
	DFG *getDFG(Function &t_F, list<Loop *> * targetFunctions);
	CGRA *getCGRA(Options *opts);
};

Options *setupOptions();
TClapOptions *setupOptionsTClap(int argc, char **argv);
void addDefaultKernels(map<string, list<int>*>*);

#define OPTIONS_H
#endif
