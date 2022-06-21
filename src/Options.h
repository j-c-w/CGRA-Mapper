#ifndef OPTIONS_H

// TODO -- These are broken --- want to figure out how to do this
// gobal thing.
#include <llvm/Support/CommandLine.h>
#include "DFG.h"
#include "CGRA.h"

#include<string>
#include <map>
#include <list>
#include "OperationMap.h"
using namespace std;

class Options {
	public:
		Options();
		bool BuildCGRA;
		bool UseRewriter;
		bool UseEGraphs;

		bool DebugOperationMap;
		bool DebugRustConversion;
		bool DebugMappingLoop;
		bool PrintMappingFailures;
		bool PrintOperationCount;
		
		std::string Params;
};

// Various parameters should be setup in a single algorihtm.
class Parameters {
	public:
	int rows;
	int columns;
	bool targetEntireFunction;
	bool targetNested;
	bool doCGRAMapping;
	bool isStaticElasticCGRA;
	bool isTrimmedDemo;
	int ctrlMemConstraint;
	int bypassConstraint;
	int regConstraint;
	bool precisionAware;
	bool heterogeneity;
	bool heuristicMapping;
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
void addDefaultKernels(map<string, list<int>*>*);

#define OPTIONS_H
#endif
