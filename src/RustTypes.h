#include <stdint.h>


#ifndef RustTypes_H
#define RustTypes_H

#ifdef __cplusplus
extern "C" {
#endif

// Leaves should be first.
typedef struct RustNode {
	const char* op;

	uint16_t num_children;
	uint32_t *child_ids;
} RustNode;

typedef struct RustDFG {
	RustNode *nodes;
	uint32_t num_nodes;
} RustDFG;

typedef struct RustDFGList {
	RustDFG *dfgs;
	uint32_t num_dfgs;
} RustDFGList;

typedef struct Rulesets {
	const char **names;
	uint32_t num_names;
} Rulesets;

RustDFGList optimize_with_egraphs(RustDFG input, Rulesets rules, const char *cgra_params_file, bool print_used_rules, const char *egraph_strategy);
RustDFGList optimize_with_graphs(RustDFG input, Rulesets rules, const char *cgra_params_file, bool frequency_cost, bool print_used_rules);

#ifdef __cplusplus
}

#endif

// Various helper functions (not part of interface with rust)
#include <string>

std::string rnode_as_string(RustNode node);

#endif
