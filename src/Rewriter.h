#include<list>
#include<string>
// #include "DFG.h"
// #include "CGRA.h"

#include <llvm/IR/Instruction.h>
#include <llvm/IR/Instructions.h>

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
				// Replace this node with an add node and change
				// the children.

				// Not really sure how to modify this stuff?
				DFGNode *new_node = new DFGNode(inserted_ids++, false, llvm::Instruction::Mul, "Mul");
				DFGNode *minus_one = new DFGNode(inserted_ids++, false, llvm::Instruction::Mul, "Mul");
				dfgNode->setInstruction(llvm::Instruction::Add, "Add");
				bool is_first = true;

				// Splice this in:
				DFGEdge *old_op = dfgNode->getPredEdge(1)
				dfgNode->setPredEdge(1, new_node)

				// Think this just adds
				new_node->setInEdge(old_op);
				// TODO --- how do we insert the -1?

				applied = true;
			}
		}

		return applied;
	}
};
