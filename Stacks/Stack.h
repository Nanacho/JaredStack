#pragma once
#include <iostream>
#include "Constants.h"

const int STACK_MAX = 20;

class Stack {
public:
	Stack();

	bool full();
	bool empty();
	char peek() const; // returns value on the top of the stack
	char pop();
	bool push(char termOrOperator);
	int size();

private:
	char stack[STACK_MAX];
	unsigned int top;
};