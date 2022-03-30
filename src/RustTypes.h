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

RustDFGList optimize_with_egraphs(RustDFG input);

#ifdef __cplusplus
}
#endif

#endif