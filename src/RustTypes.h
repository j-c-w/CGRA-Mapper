#include <stdint>
// Leaves should be first.
typedef struct RustNode {
	char* op;

	int32_t num_children;
	int32_t *child_ids;
} RustNode;

typedef *RustNode RustDFG;

RustDFG *optimize_with_egraphs(RustDFG input);
