#include<list>
#include<string>
#include "DFG.h"
#include "CGRA.h"

list<* DFG> *rewrite_for_CGRA(CGRA *cgra, DFG *dfg);

class RewriteRule {
	void applyTo(DFG *graph);
};

class SubToAddNeg: RewriteRule {
	void applyTo(DFG *graph) {
		// Search the DFG graph for x - y and transform to x + (-1) * y
		for (DFGNode *dfgNode: graph->nodes) {
			if (dfgNode->isSub()) {
				// Replace this node with an add node and change
				// the children.
				list<DFGNode*> *subnodes = dfgNode->getSuccNodes();
				// There should be two elements in this:
				list<DFGNode *>::iterator iter = subnodes.begin();
				DFGNode *op1 = *iter;
				advance(iter, 1);
				DFGNode *op2 = *iter;


			}
		}
	}
}
