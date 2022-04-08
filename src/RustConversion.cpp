#include "CGRA.h"
#include "DFG.h"
#include "RustTypes.h"
#include "RustConversion.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdexcept>

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
		errs() << "ADDing ID " << id_map.at(succ->getID()) << " from " << succ->getID() << "\n";
		i ++;
	}

	RustNode rnode;
	// DEBUG
	std::cout << n->getOpcodeName().c_str() << std::endl;
  // TODO: free memory somewhere
  char* opbuf = (char*) malloc((strlen(n->getOpcodeName().c_str()) + 1) * sizeof(char));
  strcpy(opbuf, n->getOpcodeName().c_str());
  rnode.op = opbuf;
	rnode.num_children = num_children;
	rnode.child_ids = child_ids;

	return rnode;
}

RustDFG toRustDFG(DFG *dfg) {
	map<int, int> id_lookup; // Translate between the IDs used in the DFG and the implicit IDs used in the Rust DFG.

	// Need to break cycles before we convert into a rust DFG.
	dfg->breakCycles();

	// RustNode *nodes = (RustNode* )malloc(sizeof(RustNode) * dfg->nodes.size());
	auto nodes = std::make_unique<RustNode[]>(dfg->nodes.size());
	int node_index = 0;
	list<DFGNode *> ordered_nodes = topo_sort(dfg->nodes);

	// Build a lookup table for names.
	for (DFGNode *n : ordered_nodes) {
		id_lookup.insert({n->getID(), node_index});
		node_index ++;
	}

	node_index = 0;
	for (DFGNode *n : ordered_nodes) {
		errs() << "Adding " << n->getID() << ", " << node_index << "to pattern\n";
		nodes[node_index] = toRustNode(n, id_lookup);
		node_index ++;
	}

	RustDFG rustDfg;
	rustDfg.nodes = nodes.release();
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
	errs() << "Starting to convert to DFG\n";
	// stacks for DFS of the nodes.
	list<RustNode> rnodes;
	list<int> indexes;
	rnodes.push_back(rustDfg.nodes[0]);
	indexes.push_back(0);

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
		errs() << "RNodes: Remaining size " << rnodes.size() << "\n";
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

			errs() << "Adding child " << child;
			rnodes.push_back(rustDfg.nodes[child]);
			indexes.push_back(child);
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

// Only works for loop-free graphs.
list <DFGNode *> topo_sort(list <DFGNode *> in_nodes) {
	list<DFGNode*> out_nodes;
	set<DFGNode*> added_nodes;
	int iteration_count = 0;

	while (out_nodes.size() < in_nodes.size()) {
		// errs() << "Starting iteration " << iteration_count << "\n";
		// errs() << "Added nodes size is " << added_nodes.size() << ", " << in_nodes.size() << "\n";
		if (iteration_count > in_nodes.size()) {
			errs() << "Yet to add instructions: " ;
			for (DFGNode * still_to_add : in_nodes) {
				if (added_nodes.find(still_to_add) == added_nodes.end()) {
					errs() << still_to_add->asString() << "\n ";
				} else {
					// node was added
				}
			}
			errs() << "\n";
			throw std::domain_error("Unsupported Circular DFG --- Only inner loops are supported for scheduling.");
		}
		iteration_count ++;
		for (DFGNode *n : in_nodes) {
			// errs() << "Looking at node " << n->asString() << "\n";
			if (added_nodes.find(n) != added_nodes.end()) {
				// errs() << "(Already added)\n";
				// Already added this node.
				continue;
			} else {
				// errs() << "(Looking to add...)\n";
			}

			// Check if the node can be added.
			bool can_add = true;
			for (DFGNode *pNode : *n->getSuccNodes()) {
				if (added_nodes.find(pNode) == added_nodes.end()) {
					// we haven't yet added the dependency.
					// errs() << "Failed to add due to node " << pNode ->asString() << "\n";
					can_add = false;
				}
			}

			if (can_add) {
				// errs() << "(Adding) node\n";
				out_nodes.push_back(n);
				added_nodes.insert(n);
			}
		}
	}

	// Need to return the 'root' node first.
	// out_nodes.reverse();
	return out_nodes;
}
