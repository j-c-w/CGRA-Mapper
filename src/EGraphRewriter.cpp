#include <list>
#include <iostream>

#include "DFG.h"
#include "CGRA.h"
#include "EGraphRewriter.h"

list<DFG *> *rewrite_with_egraphs(CGRA * cgra, DFG * dfg) {
	// TODO -- do something?
	list<DFG*> *results = new list<DFG*>();
	results->push_back(dfg); // think it probably crashes if it's empty.  I dunno.
	return results;
}
