// DFS: postorder and inorder.
// Exercise: Indent the printed tree.
#include <vector>
#include <iostream>
#include <string>

typedef struct TreeNode *PtrToNode;
typedef std::string DataType;

class TreeNode {
	DataType data;
public:
	PtrToNode left, right;
	TreeNode(DataType data);
	void addChild(PtrToNode);
	void print();
};
TreeNode::TreeNode(DataType data) {
	this->data = data;
	this->left = this->right = NULL;
}
void TreeNode::addChild(PtrToNode child) {
	if (left) right = child;
	else left = child;
}
void TreeNode::print() {
	std::cout << data;
}
class Tree {
	PtrToNode root;
public:
	Tree():root(NULL) { }
	PtrToNode createNode(DataType);
	void print();
	void inorder();
	void inorder(PtrToNode);
	void postorder();
	void postorder(PtrToNode);
};


void Tree::inorder(PtrToNode rr) {
	if (rr) {
		inorder(rr->left);
		rr->print();
		inorder(rr->right);
	}
}
void Tree::inorder() {
	inorder(root);
	std::cout << std::endl;
}
void Tree::postorder(PtrToNode rr) {
	if (rr) {
		postorder(rr->left);
		postorder(rr->right);
		rr->print();
	}
}
void Tree::postorder() {
	postorder(root);
	std::cout << std::endl;
}
void Tree::print() {
	postorder();
	//inorder();
}
PtrToNode Tree::createNode(DataType data) {
	PtrToNode ptr = new TreeNode(data);
	if (root == NULL) root = ptr;
	return ptr;
}
int main() {
	Tree t;
	PtrToNode root = t.createNode("+");
	PtrToNode plusleft = t.createNode("+");
	PtrToNode multright = t.createNode("*");
	PtrToNode a = t.createNode("a");
	PtrToNode multleft = t.createNode("*");
	PtrToNode b = t.createNode("b");
	PtrToNode c = t.createNode("c");
	PtrToNode plusright = t.createNode("+");
	PtrToNode g = t.createNode("g");
	PtrToNode multlast = t.createNode("*");
	PtrToNode f = t.createNode("f");
	PtrToNode d = t.createNode("d");
	PtrToNode e = t.createNode("e");
	
	root->addChild(plusleft);
	root->addChild(multright);
	plusleft->addChild(a);
	plusleft->addChild(multleft);
	multleft->addChild(b);
	multleft->addChild(c);
	multright->addChild(plusright);
	multright->addChild(g);
	plusright->addChild(multlast);
	plusright->addChild(f);
	multlast->addChild(d);
	multlast->addChild(e);

	t.print();
}
