#include <list>
#include <iostream>
#include <string>
// #include "DFG.h"
// #include "CGRA.h"

#include <llvm/IR/Instruction.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IRBuilder.h>

list<DFG*> *rewrite_for_CGRA(CGRA *cgra, DFG *dfg);
// Just need to give things unique ids I thkn -- not sure
// what they are used for.
static int inserted_ids;

class RewriteRule {
	// Return true if the rule was applied anywhere.
	bool applyTo(DFG *graph);
};

class SubToAddNeg: RewriteRule {
	bool applyTo(DFG *graph) {
		bool applied = false;
		// Search the DFG graph for x - y and transform to x + (-1) * y
		for (DFGNode *dfgNode: graph->nodes) {
			if (dfgNode->isSub()) {
				cout << dfgNode->asString() << endl;
			}
		}

		return applied;
	}
};
