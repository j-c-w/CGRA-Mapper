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

bool debugRustConversion = false;

RustNode toRustNode(DFGNode *n, map<int, int> id_map) {
	uint32_t num_children = n->getPredNodes()->size();
	if (debugRustConversion) {
		errs() << "Converting node (" << num_children << " children) from DFG to Rust: " << n->asString() << "\n";
	}
	uint32_t *child_ids = (uint32_t*) malloc(num_children * sizeof(uint32_t));

	int i = 0;
	for (DFGNode *pred: *n->getPredNodes()) {
		child_ids[i] = id_map[pred->getID()];
		if (debugRustConversion) {
			errs() << "ADDing ID " << child_ids[i] << " --same as-- " << id_map.at(pred->getID()) << " from " << pred->getID() << "\n";
			errs() << "ID was for node " << pred->asString() << "\n";
		}
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

	if (debugRustConversion) {
		errs() << "Child IDs are: ";
		for (int i = 0; i < rnode.num_children; i ++) {
			errs() << rnode.child_ids[i] << ", ";
		}
		errs() << "\n";
	}

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
		if (debugRustConversion) {
			errs() << "Setting ID of " << n->asString() << " to " << node_index << "\n";
		}
		id_lookup.insert({n->getID(), node_index});
		node_index ++;
	}

	node_index = 0;
	for (DFGNode *n : ordered_nodes) {
		if (debugRustConversion)
			errs() << "Adding " << n->getID() << ", " << node_index << "to pattern\n";
		nodes[node_index] = toRustNode(n, id_lookup);
		node_index ++;
	}

	RustDFG rustDfg;
	rustDfg.nodes = nodes.release();
	rustDfg.num_nodes = node_index;

	// DEBUG >>>
	if (debugRustConversion) {
		for (int i = 0; i < rustDfg.num_nodes; i++) {
			auto node = rustDfg.nodes[i];
			std::cout << i << ": " << node.op << " with children: [ ";
			for (int j = 0; j < node.num_children; j++) {
				std::cout << node.child_ids[j] << " ";
			}
			std::cout << "]" << std::endl;
		}
	}
	// <<<

	return rustDfg;
}

DFGNode *toDFGNode(RustNode n, int32_t id) {
	DFGNode *node = new DFGNode(id, false, nullptr, std::string(n.op), std::string(n.op));

	return node;
}

DFGEdge *toDFGEdge(int32_t fromid, int32_t toid, map<int32_t, DFGNode*> *lookup) {
	DFGEdge *edge = new DFGEdge(/* todo does this need to be unique? */0, lookup->at(toid), lookup->at(fromid));

	return edge;
}

// we should probably use the stdlib thing to do this?
DFGNode *getNodeFromIndex(list<DFGNode *> *nodes, int index) {
	int count = 0;
	for (DFGNode *node: *nodes) {
		if (count == index) {
			return node;
		}
		count ++;
	}

	return nullptr;
}

DFG* toDFG(RustDFG rustDfg) {
	if (debugRustConversion)
		errs() << "Starting to convert to DFG\n";

	list<DFGNode*> *dnodes = new list<DFGNode*>();
	// for creating th real edges
	map<int, DFGNode*> *dnode_map = new map<int, DFGNode*>();
	// DFG Edge requires the nodes as arguments.
	// keep just the indexes in this, then build
	// up the actual edges once all the nodes
	// are created.
	list<TempEdge> *temp_edges = new list<TempEdge>();
	list<DFGEdge*> *dedges = new list<DFGEdge*>();

	if (debugRustConversion)
		errs() << "Starting to process graph: Nodes in total is " << rustDfg.num_nodes << "\n";
	for (int i = 0; i < rustDfg.num_nodes; i ++) {
		if (debugRustConversion)
			errs() << "Starting on RNode " << i << "\n";
		// get the children from this node.
		RustNode rnode = rustDfg.nodes[i];
		if (debugRustConversion) {
			errs() << "Inspecting RNode: " << rnode_as_string(rnode) << "\n";
			errs() << "Node has " << rnode.num_children << " children\n";
		}
		DFGNode *dfgnode = toDFGNode(rnode, i);
		dnode_map->insert({i, dfgnode});
		if (debugRustConversion)
			errs() << "Created DFGNode " << dfgnode->asString() << " (Edges not yet attached)\n";
		// keep track of the edges we'll need to construct later.
		for (int j = 0; j < rnode.num_children; j ++) {
			TempEdge temp_edge;
			temp_edge.to = i;
			temp_edge.from = rnode.child_ids[j];
			temp_edges->push_back(temp_edge);
		}

		dnodes->push_back(dfgnode);
	}

	// Create the edges from the temp edge list.
	for (TempEdge e : *temp_edges) {
		DFGEdge *new_edge = toDFGEdge(e.from, e.to, dnode_map);
		dedges->push_back(new_edge);

		// Update the appropriate nodes with this edge:
		// Order is swapped --- between an ast operation-like order and a DFG-like order
		DFGNode *fromNode = dnode_map->at(e.to);
		DFGNode *toNode   = dnode_map->at(e.from);

		fromNode->setOutEdge(new_edge);
		toNode->setInEdge(new_edge);
		if (debugRustConversion)
			errs() << "Added edge between " << std::to_string(e.from) << " and " << std::to_string(e.to) << "\n";
	}

	// Now, create the DFG:
	DFG *newDFG = new DFG(*dnodes, *dedges);
	return newDFG;
}

// As below, but use the rewrite_with_graphs interface instead.
list<DFG*> *rewrite_with_graphs(Options *opts, CGRA *cgra, DFG *dfg) {
	RustDFG rdfg = toRustDFG(dfg);
	if (opts->DebugRustConversion) {
		Rulesets r = opts->getRulesets();
		for (int i = 0; i < r.num_names; i ++) {
			errs() << "Using rulesets " << r.names[i] << ", ";
			int j = 0;
			while (r.names[i][j] != '\0') {
				errs() << r.names[i][j];
				j ++;
			}
		}
		errs() << "Using rulesets " << opts->getRulesetNames() << "\n";
	}
  bool frequency_cost = true;
	RustDFGList rust_results = optimize_with_graphs(rdfg, opts->getRulesets(), opts->Params.c_str(), frequency_cost);

	if (opts->DebugRustConversion) {
		errs() << "Sent over a graph to the graph rewriter: " << dfg->asString() << "\n";
	}

	list<DFG*> *dfg_results = new list<DFG*>();
	for (int i = 0; i < rust_results.num_dfgs; i ++) {
		dfg_results->push_back(toDFG(rust_results.dfgs[i]));
	}

	if (opts->DebugRustConversion) {
		errs() << "Returning " << rust_results.num_dfgs << "graphs from the rust wrapper";
	}

	return dfg_results;
}

list<DFG*> *rewrite_with_egraphs(Options *opts, CGRA *cgra, DFG *dfg) {
	debugRustConversion = opts->DebugRustConversion;
	// Create the Rust DFGs:
	RustDFG rdfg = toRustDFG(dfg);
	// Call the rewriter
	// Results are null-terminated.
	if (opts->DebugRustConversion) {
		errs() << "Using rulesets " << opts->getRulesetNames() << "\n";
	}
  bool frequency_cost = true;
	RustDFGList rust_results = optimize_with_egraphs(rdfg, opts->getRulesets(), opts->Params.c_str(), frequency_cost);
	// Go through and look at the outputs

	if (opts->DebugRustConversion) {
		errs() << "Sent over graph: " << dfg->asString() << "\n";
	}
	list<DFG*> *dfg_results = new list<DFG*>();
	for (int i = 0; i < rust_results.num_dfgs; i ++) {
		// convert each result to a dfg.
		dfg_results->push_back(toDFG(rust_results.dfgs[i]));
	}
	if (opts->DebugRustConversion) {
		errs() << "Returning " << rust_results.num_dfgs << " graphs from the Rust wrapper\n";
		errs() << "First result is " << dfg_results->front()->asString();
	}
	return dfg_results;
}

// Only works for loop-free graphs.
list <DFGNode *> topo_sort(list <DFGNode *> in_nodes) {
	list<DFGNode*> out_nodes;
	set<DFGNode*> added_nodes;
	int iteration_count = 0;

	while (out_nodes.size() < in_nodes.size()) {
		if (debugRustConversion) {
			errs() << "Starting iteration " << iteration_count << "\n";
			errs() << "Added nodes size is " << added_nodes.size() << ", " << in_nodes.size() << "\n";
		}
		if (iteration_count > in_nodes.size()) {
			errs() << "Yet to add instructions: " ;
			errs() << "Iteration count reached " << iteration_count << " but only had " << in_nodes.size() << " in nodes\n";
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
				if (debugRustConversion) {
					errs() << "(Already added)\n";
				}
				// Already added this node.
				continue;
			} else {
				if (debugRustConversion) {
					errs() << "(Looking to add...)\n";
				}
			}

			// Check if the node can be added.
			bool can_add = true;
			for (DFGNode *pNode : *n->getPredNodes()) {
				if (added_nodes.find(pNode) == added_nodes.end()) {
					// we haven't yet added the dependency.
					if (debugRustConversion) {
						errs() << "Failed to add due to node " << pNode ->asString() << "\n";
					}
					can_add = false;
				}
			}

			if (can_add) {
				if (debugRustConversion) {
					errs() << "(Adding) node\n";
				}
				out_nodes.push_back(n);
				added_nodes.insert(n);
			}
		}
	}

	// Need to return the 'leaf' nodes first.
	// out_nodes.reverse();
	return out_nodes;
}
