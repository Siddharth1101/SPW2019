// postfix2expr.
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
int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <postfix-expr>" << std::endl;
		return 1;
	}
	Postfix expr(argv[1]);
	std::cout << expr.eval() << std::endl;

	return 0;
}
