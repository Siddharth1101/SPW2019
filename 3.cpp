#include <vector>
#include <iostream>

typedef struct TreeNode *PtrToNode;
typedef char DataType;

struct TreeNode {
	DataType data;
	std::vector<PtrToNode> children;
	TreeNode(DataType data);
	void addChild(PtrToNode);
	void print();
};
TreeNode::TreeNode(DataType data) {
	this->data = data;
}
void TreeNode::addChild(PtrToNode child) {
	children.push_back(child);
}
void TreeNode::print() {
	std::cout << data << std::endl;
}
class Tree {
	PtrToNode root;
public:
	Tree():root(NULL) { }
	PtrToNode createNode(DataType);
	void print();
	void preorder();
	void preorder(PtrToNode);
};

void Tree::preorder(PtrToNode rr) {
	if (rr) {
		rr->print();
		for (auto child:rr->children) preorder(child);
	}
}
void Tree::preorder() {
	preorder(root);
}
void Tree::print() {
	preorder();
}
PtrToNode Tree::createNode(DataType data) {
	PtrToNode ptr = new TreeNode(data);
	if (root == NULL) root = ptr;
	return ptr;
}
int main() {
	Tree t;
	PtrToNode A = t.createNode('A');
	PtrToNode B = t.createNode('B');
	PtrToNode C = t.createNode('C');
	PtrToNode D = t.createNode('D');
	PtrToNode E = t.createNode('E');
	PtrToNode F = t.createNode('F');
	PtrToNode G = t.createNode('G');
	PtrToNode H = t.createNode('H');
	PtrToNode I = t.createNode('I');
	
	A->addChild(B);
	A->addChild(C);
	B->addChild(D);
	B->addChild(E);
	B->addChild(F);
	C->addChild(G);
	C->addChild(H);
	C->addChild(I);

	t.print();
}
