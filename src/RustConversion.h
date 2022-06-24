#include "CGRA.h"
#include "DFG.h"
#include "DFGNode.h"
#include <list>
#include "Options.h"

list <DFG*> *rewrite_with_egraphs(Options *options, CGRA *cgra, DFG *dfg);
list <DFG*> *rewrite_with_graphs(Options *options, CGRA *cgra, DFG *dfg);
list <DFGNode *> topo_sort(list <DFGNode *> in_nodes);
