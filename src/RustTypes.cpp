#include "RustTypes.h"
#include <string>

std::string rnode_as_string(RustNode node) {
	return "Node: operation " + std::string(node.op) + " with " + std::to_string(node.num_children); // todo -- print IDs
}
