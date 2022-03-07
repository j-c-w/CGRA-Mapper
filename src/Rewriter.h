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
	public:
		RewriteRule() {};
	virtual bool applyTo(DFG *graph) {
		cout << "Warning: Calling applyTo on base rewrite" << endl;
		return false;
	}
	virtual std::string toString() { return std::string("RewriteBaseClass"); }
};

class SubToAddNeg: public RewriteRule {
	public:
	SubToAddNeg () { };
	virtual bool applyTo(DFG *graph) {
		bool applied = false;
		// Search the DFG graph for x - y and transform to x + (-1) * y
		for (DFGNode *dfgNode: graph->nodes) {
			cout << "Trying to apply rewrite rule to a new node" << endl;
			if (dfgNode->isSub()) {
				cout << "Found sub:" << endl;
				cout << dfgNode->asString() << endl;

				// Get the args for this instruction:

				// Create the new add node:
				Instruction add_instruction = 
				DFGNode *addNode = new DFGNode(inserted_ids ++, false, add_instruction, "InsertedAdd");
				// TODO --- create the multiply node also.

				// Now, update the graph with this new node:
			}
		}

		return applied;
	}

	virtual std::string toString() {
		return std::string("SubtractToAddNegative");
	}
};
