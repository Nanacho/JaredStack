#include "Stack.h"
#include <string>

int evaluate(std::string statement);
int getNumFromChar(char c);
bool isNum(char c);
std::string fix(std::string expression);
std::string removeWhiteSpace(std::string statement);

int main() {
	std::string infix = "5 + 4 * 6 - 3";
	std::string postfix = fix(removeWhiteSpace(infix));
	std::cout << evaluate(postfix);

	return 1;
}

int evaluate(std::string statement) {
	Stack numbers;
	int currentAnswer = 0;

	for (int i = 0; i < statement.size(); ++i) {
		char c = statement.at(i);
		if (isNum(c))
			numbers.push(c);

		if (!isNum(c)) {
			if (numbers.size() < 2) {
				std::cout << "Error! Cannot be solved. Not enough values!" << std::endl;
				break;
			}
			else {
				int result = 0;
				//numbers.pop();
				int number1 = numbers.pop() - 48;
				int number2 = numbers.pop() - 48;

				if (c == '+')
					result = number2 + number1;
				else if (c == '-')
					result = number2 - number1;
				else if (c == '*')
					result = number2 * number1;
				else if (c == '/')
					result = number2 / number1;

				numbers.push(result);
			}
		}
	}
	if (numbers.size() == 1)
		return static_cast<int>(numbers.peek());
}

int getNumFromChar(char c) {
	int num = c - 48;
	if (num < 0 || num > 9)
		return -1;
	return num;
}

bool isNum(char c) {
	if (getNumFromChar(c) == -1)
		return false;
	return true;
}

int getPrecedence(char c) {
	if (c == '*' || c == '/')
		return 2;
	if (c == '+' || c == '-')
		return 1;
	if (c == '(' || c == ')')
		return 0;
	return -1;
}

bool isOperator(char c) {
	switch (c) {
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	default:
		return false;
	}
}

std::string fix(std::string expression) {
	Stack operations;
	std::string post;

	for (int i = 0; i < expression.size(); i++) {
		char c = expression.at(i);
		if (isNum(c))
			post.push_back(c);
		else if (c == '(') {
			operations.push(c);
		}
		else if (isOperator(c)) {
			while (!operations.empty() && (getPrecedence(operations.peek()) >= getPrecedence(c))) {
				post.push_back(operations.pop());
			}
			operations.push(c);
		}
		else if (c == ')') {
			while (!operations.empty() && operations.peek() != '(') {
				post.push_back(operations.pop());
			}
			operations.pop();
		}
	}

	while (!operations.empty())
		post.push_back(operations.pop());

	return post;
}

std::string removeWhiteSpace(std::string statement) {
	std::string temp;
	for (int i = 0; i < statement.size(); i++) {
		if (statement[i] != ' ')
			temp.push_back(statement[i]);
	}
	return temp;
}