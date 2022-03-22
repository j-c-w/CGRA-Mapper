#include <stdint.h>


#ifndef RustTypes_H
#define RustTypes_H

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

#endif

#ifdef __cplusplus
extern "C" {
#endif
	// NOTE: need to get the number of graphs out of this.
	RustDFGList optimize_with_egraphs(RustDFG input);
#ifdef __cplusplus
}
#endif
