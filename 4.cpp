// DFS: preorder.
// Exercise: Indent the printed tree.
#include <vector>
#include <iostream>
#include <string>

typedef struct TreeNode *PtrToNode;
typedef std::string DataType;

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
	PtrToNode slash = t.createNode("/");
	PtrToNode home = t.createNode("home");
	PtrToNode somesh = t.createNode("somesh");
	PtrToNode saurabh = t.createNode("saurabh");
	PtrToNode jk = t.createNode("jk");
	PtrToNode acad = t.createNode("acad");
	PtrToNode intern = t.createNode("intern");
	PtrToNode test = t.createNode("test.c");
	PtrToNode one = t.createNode("1.c");
	PtrToNode two = t.createNode("2.c");
	PtrToNode three = t.createNode("3.c");
	PtrToNode ibm = t.createNode("ibm");
	PtrToNode first = t.createNode("first");
	PtrToNode second = t.createNode("second");
	PtrToNode third = t.createNode("third");
	PtrToNode readme1 = t.createNode("readme");
	PtrToNode readme2 = t.createNode("readme");
	PtrToNode readme3 = t.createNode("readme");
	PtrToNode cv = t.createNode("cv.pdf");
	PtrToNode cs1100 = t.createNode("cs1100");
	PtrToNode spw = t.createNode("spw");
	PtrToNode bintree = t.createNode("bintree");
	PtrToNode searchtree = t.createNode("searchtree");
	PtrToNode bintreeonecpp = t.createNode("1.cpp");
	PtrToNode bintreetwocpp = t.createNode("2.cpp");
	PtrToNode trees = t.createNode("trees.pdf");
	PtrToNode searchtreeonecpp = t.createNode("1.cpp");
	PtrToNode searchtreetwocpp = t.createNode("2.cpp");
	PtrToNode bst = t.createNode("bst.pdf");
	
	slash->addChild(home);
	home->addChild(somesh);
	home->addChild(saurabh);
	home->addChild(jk);
	somesh->addChild(acad);
	somesh->addChild(intern);
	somesh->addChild(test);
	acad->addChild(one);
	acad->addChild(two);
	acad->addChild(three);
	intern->addChild(ibm);
	ibm->addChild(first);
	ibm->addChild(second);
	ibm->addChild(third);
	first->addChild(readme1);
	second->addChild(readme2);
	third->addChild(readme3);
	saurabh->addChild(cv);
	jk->addChild(cs1100);
	jk->addChild(spw);
	spw->addChild(bintree);
	spw->addChild(searchtree);
	bintree->addChild(bintreeonecpp);
	bintree->addChild(bintreetwocpp);
	bintree->addChild(trees);
	searchtree->addChild(searchtreeonecpp);
	searchtree->addChild(searchtreetwocpp);
	searchtree->addChild(bst);

	t.print();
}
