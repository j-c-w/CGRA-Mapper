#include <list>
#include "DFG.h"
#include "CGRA.h"
#include "Rewriter.h"
#include <iostream>
using namespace std;

list<RewriteRule*> rewrites = {
	new SubToAddNeg()
};

list<DFG*> *rewrite_for_CGRA(CGRA *cgra, DFG *dfg) {
	cout << "Running rewriter" << endl;
	list<DFG*> *results = new list<DFG*>();
	results->push_back(dfg); // unapplied DFG.

	for (RewriteRule* r : rewrites) {
		cout << "Running rule " << r->toString() << endl;
		// Note the current copy-constructor re-initializes
		// from the original function, doesn't deep
		// copy the structures modified so far (although
		// it should do exactly that)
		DFG *copy = new DFG(*dfg);
		// Only add to the results list if we
		// apply the rule.
		bool any_applied = r->applyTo(copy);

		if (any_applied) {
			results->push_back(copy);
		}
	}

	return results;
}
