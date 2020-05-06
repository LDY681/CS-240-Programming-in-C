// Example program to test Stack class

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

using namespace std;


void test1() {
	Stack * stack = new Stack(10);
	stack->push(40);
	stack->push(50);
	stack->push(60);
	stack->push(70);
	stack->push(80);

	printf("top=%d max=%d\n", stack->getTop(), stack->getMaxStack());
	stack->print();

	double val;
	stack->pop(val);
	stack->pop(val);
	cout << "val=" << val << endl;

	stack->print();

	stack->push(4);
	stack->push(5);
	stack->pop(val);
	cout << "val=" << val << endl;

	stack->print();

	delete stack;
}

int
main(int argc, char **argv) {
	test1();

	exit(0);
}


