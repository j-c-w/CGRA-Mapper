#include <list>
#include "DFG.h"
#include "CGRA.h"

list<RewriteRule> rewrites = {
	SubToAddNeg()
};

list<* DFG> *rewrite_for_CGRA(CGRA *cgra, DFG *dfg) {
	list<* DFG> *results = new List< *DFG>();
	results->push_back(dfg); // unapplied DFG.

	for (RewriteRule r : rewrites) {
		// Note the current copy-constructor re-initializes
		// from the original function, doesn't deep
		// copy the structures modified so far (although
		// it should do exactly that)
		DFG *copy = DFG(dfg);
		// Only add to the results list if we
		// apply the rule.
		bool any_applied = false;

		for (DFGNode node : dfg->nodes) {
			bool applied = r.applyTo(node);
			any_applied = applied || any_applied;
		}

		if (any_applied) {
			results->push_back(copy);
		}
	}

	return results
}
