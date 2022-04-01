#include "CGRA.h"
#include "DFG.h"
#include "RustTypes.h"
#include <stdlib.h>
#include <stdint.h>

#include <list>
#include <map>
#include <set>

using namespace std;

typedef struct TempEdge {
	int32_t from;
	int32_t to;
} TempEdge;

RustNode toRustNode(DFGNode *n, map<int, int> id_map) {
	uint32_t num_children = n->getSuccNodes()->size();

	uint32_t *child_ids = (uint32_t*) malloc(num_children * sizeof(uint32_t));

	int i = 0;
	for (DFGNode *succ: *n->getSuccNodes()) {
		child_ids[i] = id_map[succ->getID()];
		i ++;
	}

	RustNode rnode;
	// DEBUG
	std::cout << n->getOpcodeName().c_str() << std::endl;
	rnode.op = n->getOpcodeName().c_str();
	rnode.num_children = num_children;
	rnode.child_ids = child_ids;

	return rnode;
}

RustDFG toRustDFG(DFG *dfg) {
	map<int, int> id_lookup; // Translate between the IDs used in the DFG and the implicit IDs used in the Rust DFG.

	RustNode *nodes = (RustNode* )malloc(sizeof(RustNode) * dfg->nodes.size());
	int node_index = 0;
	list<DFGNode *> ordered_nodes = topo_sort(dfg->nodes);

	// TODO --- order the nodes appropriately.
	for (DFGNode *n : ordered_nodes) {
		id_lookup.insert({n->getID(), node_index});
		nodes[node_index] = toRustNode(n, id_lookup);

		node_index ++;
	}

	RustDFG rustDfg;
	rustDfg.nodes = nodes;
	rustDfg.num_nodes = node_index;

	// DEBUG >>>
	for (int i = 0; i < rustDfg.num_nodes; i++) {
		auto node = rustDfg.nodes[i];
		std::cout << i << ": " << node.op << " with children: [ ";
		for (int j = 0; j < node.num_children; j++) {
			std::cout << node.child_ids[j] << " ";
		}
		std::cout << "]" << std::endl;
	}
	// <<<

	return rustDfg;
}

DFGNode *toDFGNode(RustNode n, int32_t id) {
	DFGNode *node = new DFGNode(id, false, nullptr, std::string(n.op), std::string(n.op));

	return node;
}

DFGEdge *toDFGEdge(int32_t fromid, int32_t toid, map<int32_t, DFGNode*> *lookup) {
	DFGEdge *edge = new DFGEdge(/* todo does this need to be unique? */0, lookup->at(fromid), lookup->at(toid));

	return edge;
}

DFG* toDFG(RustDFG rustDfg) {
	// stacks for DFS of the nodes.
	list<RustNode> rnodes;
	list<int> indexes;
	// avoid getting caught out by loops.
	set<int> visited_nodes;
	rnodes.push_back(rustDfg.nodes[0]);
	indexes.push_back(0);
	visited_nodes.insert(0);

	list<DFGNode*> *dnodes = new list<DFGNode*>();
	// for creating th real edges
	map<int, DFGNode*> *dnode_map = new map<int, DFGNode*>();
	// DFG Edge requires the nodes as arguments.
	// keep just the indexes in this, then build
	// up the actual edges once all the nodes
	// are created.
	list<TempEdge> *temp_edges = new list<TempEdge>();
	list<DFGEdge*> *dedges = new list<DFGEdge*>();

	while (rnodes.size() > 0) {
		// get the children from this node.
		int index = indexes.front();
		indexes.pop_front();
		RustNode rnode = rnodes.front();
		rnodes.pop_front();
		DFGNode *dfgnode = toDFGNode(rnode, index);
		dnode_map->insert({index, dfgnode});
		// keep track of the edges we'll need to construct later.
		for (int i = 0; i < rnode.num_children; i ++) {
			TempEdge temp_edge;
			temp_edge.from = index;
			temp_edge.to = rnode.child_ids[i];
			temp_edges->push_back(temp_edge);
		}

		dnodes->push_back(dfgnode);

		// Add the connecting nodes to the list.
		for (int i = 0; i < rnode.num_children; i ++) {
			int32_t child = rnode.child_ids[i];

			if (visited_nodes.count(child)) {
				// we have already visited.
				continue;
			} else {
				visited_nodes.insert(child);
				rnodes.push_back(rustDfg.nodes[child]);
				indexes.push_back(child);
			}
		}
	}

	// Create the edges from the temp edge list.
	for (TempEdge e : *temp_edges) {
		DFGEdge *new_edge = toDFGEdge(e.from, e.to, dnode_map);
		dedges->push_back(new_edge);
	}

	// Now, create the DFG:
	DFG *newDFG = new DFG(dnodes, dedges);
	return newDFG;
}

list<DFG*> *rewrite_with_egraphs(CGRA *cgra, DFG *dfg) {
	// Create the Rust DFGs:
	RustDFG rdfg = toRustDFG(dfg);
	// Call the rewriter
	// Results are null-terminated.
	RustDFGList rust_results = optimize_with_egraphs(rdfg);
	// Go through and look at the outputs

	list<DFG*> *dfg_results = new list<DFG*>();
	for (int i = 0; i < rust_results.num_dfgs; i ++) {
		// convert each result to a dfg.
		dfg_results->push_back(toDFG(rust_results.dfgs[i]));
	}
	return dfg_results;
}

list <DFGNode *> topo_sort(list <DFGNode *> in_nodes) {
	list<DFGNode*> out_nodes;
	set<DFGNode*> added_nodes;

	while (added_nodes.size() < in_nodes.size()) {
		for (DFGNode *n : in_nodes) {
			if (added_nodes.find(n) == added_nodes.end()) {
				// Already added this node.
				continue;
			}

			// Check if the node can be added.
			bool can_add = true;
			for (DFGNode *pNode : n->getPredNodes()) {
				if (added_nodes.find(pNode) == added_nodes.end()) {
					// we haven't yet added the dependency.
					can_add = false;
				}
			}

			if (can_add) {
				out_nodes.push_back(n);
			}
		}
	}

	return out_nodes;
}