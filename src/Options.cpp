#include <llvm/Support/CommandLine.h>
#include "Options.h"

// TODO --- These are broken --- want to figure out how to do this
// global thing.
using namespace llvm;
cl::opt<bool> LLVMDebugOperationMap ("debug-operation-map", cl::desc("Debug the node-by-node operation mapping"));

bool DebugOperationMap;

// To be called after application has started.  Copies the command
// line results into global variables that can be accessed
// via Options.h
void setupOptions() {
	DebugOperationMap = LLVMDebugOperationMap;
}
