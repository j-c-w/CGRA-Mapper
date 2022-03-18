#include <list>
#include <iostream>
#include <string>
// #include "DFG.h"
// #include "CGRA.h"

#include <llvm/IR/Instruction.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Transforms/Utils/BasicBlockUtils.h>
#include <memory>

list<DFG*> *rewrite_for_CGRA(CGRA *cgra, DFG *dfg);
// Just need to give things unique ids I thkn -- not sure
// what they are used for.
static int inserted_ids;

using namespace llvm;

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
		auto nodesToRemove = list<DFGNode *>();
		for (DFGNode *dfgNode: graph->nodes) {
			cout << "Trying to apply rewrite rule to a new node" << endl;
			if (dfgNode->isIntSub()) {
				cout << "Found sub:" << endl;
				cout << dfgNode->asString() << endl;

				/* // See https://stackoverflow.com/questions/40649380/replacing-instructions-in-llvm-ir */
				/* // Get the args for this instruction: */
				/* // Option 1: do this, then use the internal CGRA-mapper functions to */ 
				/* // put this back into a DFG. */
				/* llvm::Instruction *existingInstruction = dyn_cast<BinaryOperator>(dfgNode->getInst()); */
				/* BasicBlock *existingBB = existingInstruction->getParent(); */

				/* IRBuilder<> builder(existingInstruction); */
				/* Value *lhs = existingInstruction->getOperand(0); */
				/* Value *rhs = existingInstruction->getOperand(1); */
				/* Value* minus_one = llvm::ConstantInt::get(existingInstruction->getContext(), llvm::APInt(32, -1, true)); */

				/* // Create the new add node: */
				/* builder.SetInsertPoint(dfgNode->getInst()); */
				/* Instruction *mul = dyn_cast<Instruction>(builder.CreateMul(rhs, minus_one)); */
				/* Instruction *add = dyn_cast<Instruction>(builder.CreateAdd(lhs, rhs)); */

				/* // Put the node into the basci block. */
				/* BasicBlock::iterator bb_iterator = existingBB->begin(); */
				/* ReplaceInstWithValue(existingBB->getInstList(), bb_iterator, add); */

				// Option2: do the above,
				// then modify the function as appropriate.

				// llvm::Instruction add_instruction = 
				DFGNode *addNode = new DFGNode(inserted_ids ++, false, nullptr, "add", "add");
				DFGNode *mulNode = new DFGNode(inserted_ids ++, false, nullptr, "mul", "mul");

				// Modify the in-edges:
				bool first = true;
				for (DFGEdge *in_edge: dfgNode->getInEdges()) {
					// Swap the operation for the add node:
					// First one goes into the add node
					if (first) {
						in_edge->setDst(addNode);
						// and add this edge.
						addNode->setInEdge(in_edge);
						first = false;
					} else {
						// second one should go to the mul node.
						in_edge->setDst(mulNode);
						// and add this node to where it is stored.
						mulNode->setInEdge(in_edge);
					}
				}

				// Do the same for the out edges:
				for (DFGEdge *out_edge: dfgNode->getOutEdges()) {
					out_edge->setSrc(addNode);
					// and add this edge to the node where it's stored.
					addNode->setOutEdge(out_edge);
				}

				// Now, add a new edge to the graph between
				// the mul node and the add node:
				DFGEdge *newEdge = new DFGEdge(inserted_ids ++, mulNode, addNode);
				// Add this edge to the add and the mul nodes:
				mulNode->setOutEdge(newEdge);
				addNode->setInEdge(newEdge);

				// Remove the old node from the DFG.
				nodesToRemove->push_back(dfgNode);

				applied = true;
			}
		}

		for (DFGNode *n : *nodesToRemove) {
			std::cout << "Removing node " << n->asString() << std::endl;
		}
		graph->removeNodes(nodesToRemove);

		return applied;
	}

	virtual std::string toString() {
		return std::string("SubtractToAddNegative");
	}
};
