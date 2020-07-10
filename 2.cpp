#include <vector>
typedef struct TreeNode *PtrToNode;

struct TreeNode {
	int data;
	std::vector<PtrToNode> children;
};

