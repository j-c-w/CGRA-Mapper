#ifndef OPTIONS_H

// TODO -- These are broken --- want to figure out how to do this
// gobal thing.
#include <llvm/Support/CommandLine.h>

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
};

Options *setupOptions();

#define OPTIONS_H
#endif
