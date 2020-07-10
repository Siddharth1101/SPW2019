// postfix2expr.
#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <cctype>

class Postfix {
	std::string expr;

public:
	Postfix(char *lexpr):expr(lexpr) { }
	int eval();
	int eval(char c, std::stack<int> &stack);
	bool isop(char c) { return (c == '+' || c == '-' || c == '*' || c == '/'); }
	std::string tostring() { return expr; }
};

int Postfix::eval(char c, std::stack<int> &stack) {
	if (stack.size() < 2) {
		std::cerr << "Error3: invalid expression\n";
		return -3;
	}
	int val2 = stack.top();
	stack.pop();
	int val1 = stack.top();
	stack.pop();

	std::cout << "eval: " << val1 << c << val2 << std::endl;

	switch (c) {
	case '+': return val1 + val2;
	case '-': return val1 - val2;
	case '*': return val1 * val2;
	case '/': return val1 / val2;
	}
}
int Postfix::eval() {
	std::stack<int> stack;

	for (char c: expr) {
		if (isdigit(c)) {
			stack.push(c - '0');
		} else if (isop(c)) {
			stack.push(eval(c, stack));
		} else {
			std::cerr << "Error1: invalid expression\n";
			return -1;
		}
	}
	if (stack.size() != 1) {
		std::cerr << "Error2: invalid expression\n";
		return -2;
	}
	int val = stack.top();
	stack.pop();

	return val;
}
typedef struct TreeNode *PtrToNode;
typedef char DataType;

struct TreeNode {
	DataType data;
	PtrToNode left, right;
	unsigned id;
	TreeNode(DataType data);
	void setChildren(PtrToNode, PtrToNode);
	void print();
};
TreeNode::TreeNode(DataType data) {
	static int sid = 1;
	this->data = data;
	this->id = ++sid;
}
void TreeNode::setChildren(PtrToNode n1, PtrToNode n2) {
	left = n1;
	right = n2;
}
void TreeNode::print() {
	std::cout << data << std::endl;
}
class Tree {
	PtrToNode root;
public:
	Tree():root(NULL) { }
	Tree(Postfix &);
	PtrToNode createNode(DataType);
	void inorder();
	void inorder(PtrToNode);
	PtrToNode createFromPostfix(Postfix &);
	PtrToNode createNode(char c, std::stack<PtrToNode> &stack);
	void printGraphviz();
	void printGraphviz(PtrToNode);
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

PtrToNode Tree::createNode(char c, std::stack<PtrToNode> &stack) {
	if (stack.size() < 2) {
		std::cerr << "Error3: invalid expression\n";
		return NULL;
	}
	PtrToNode n2 = stack.top();
	stack.pop();
	PtrToNode n1 = stack.top();
	stack.pop();

	std::cout << "eval: " << n1->data << c << n2->data << std::endl;

	PtrToNode cptr = createNode(c);
	cptr->setChildren(n1, n2);
	return cptr;
}
PtrToNode Tree::createFromPostfix(Postfix &expr) {
	std::stack<PtrToNode> stack;

	for (char c: expr.tostring()) {
		if (isalnum(c)) {
			stack.push(createNode(c));
		} else if (expr.isop(c)) {
			stack.push(createNode(c, stack));
		} else if (isspace(c)) {
			// skip.
		} else {
			std::cerr << "Error1: invalid expression\n";
			return NULL;
		}
	}
	if (stack.size() != 1) {
		std::cerr << "Error2: invalid expression\n";
		return NULL;
	}
	root = stack.top();
	stack.pop();

	return root;
}
Tree::Tree(Postfix &expr) {
	createFromPostfix(expr);
}

PtrToNode Tree::createNode(DataType data) {
	PtrToNode ptr = new TreeNode(data);
	if (root == NULL) root = ptr;
	return ptr;
}
void Tree::printGraphviz(PtrToNode rr) {
	if (rr) {
		if (rr->left) {
			std::cout << '"' << rr->data << rr->id << '"';
			std::cout << " -> ";
			std::cout << '"' << rr->left->data << rr->left->id << '"';
			std::cout << std::endl;
			printGraphviz(rr->left);
		}
		if (rr->right) {
			std::cout << '"' << rr->data << rr->id << '"';
			std::cout << " -> ";
			std::cout << '"' << rr->right->data << rr->right->id << '"';
			std::cout << std::endl;
			printGraphviz(rr->right);
		}
	}
}
void Tree::printGraphviz() {
	std::cout << "digraph G {\n";
	printGraphviz(root);
	std::cout << "}\n";
}
int main(int argc, char *argv[]) {	
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <postfix-expr>" << std::endl;
		return 1;
	}
	Postfix expr(argv[1]);
	Tree t(expr);
	//t.inorder();
	t.printGraphviz();
}
