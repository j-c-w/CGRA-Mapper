#include "CGRA.h"
#include "DFG.h"
#include "DFGNode.h"
#include <list>

list <DFG*> *rewrite_with_egraphs(CGRA *cgra, DFG *dfg);
list <DFGNode *> topo_sort(list <DFGNode *> in_nodes);
