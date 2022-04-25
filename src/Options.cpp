#include <llvm/Support/CommandLine.h>
#include "Options.h"

using namespace llvm;

cl::opt<bool> BuildCGRA("build", cl::desc("Build the CGRA from the code rather than mapping to it."));

// op mode flags.
cl::opt<bool> UseRewriter("rewriter", cl::desc("Use the simple rewriter"));
cl::opt<bool> UseEGraphs("use-egraphs", cl::desc("Use the egraphs-based rewriter"));

// Debug flags
cl::opt<bool> PrintMappingFailures("print-mapping-failures", cl::desc("Print the operations where mapping fails"));
cl::opt<bool> DebugMappingLoop("debug-mapping-loop", cl::desc("Debug the mapping loop."));
cl::opt<bool> DebugRustConversion("debug-rust-conversion", cl::desc("Debug the egraphs interface on the C++ side"));
cl::opt<bool> LLVMDebugOperationMap ("debug-operation-map", cl::desc("Debug the node-by-node operation mapping"));

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

	return opt;
}
