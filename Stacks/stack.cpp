#include "Stack.h"

Stack::Stack() {
	top = 0;
}

bool Stack::full() {
	if (top == STACK_MAX)
		return true;
	return false;
}

bool Stack::empty() {
	if (top == 0)
		return true;
	return false;
}

char Stack::peek() const {
	return stack[top - 1];
}

char Stack::pop() {
	if (empty()) {
		std::cout << "Nothing to pop\n\n";
		return 0;
	}

	return stack[--top];
}

bool Stack::push(char termOrOperator) {
	if (full()) {
		std::cout << "Stack full.\n\n";
		return false;
	}
	
	if (termOrOperator != ' ') {
		stack[top++] = termOrOperator;
		return true;
	}

	return false;
}

int Stack::size() {
	return top;
}