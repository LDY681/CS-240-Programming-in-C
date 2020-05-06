// Stack Implementation

// Used for cout << "string"
#include <iostream>

using namespace std;

#include "Stack.h"

// Constructor
Stack::Stack(int maxStack) {
	this->maxStack = maxStack;	//this->maxStack = member of the stack class,  maxStack = the varaible pass by parameter
	stack = new double[maxStack];
	top = 0;
}

// Write other calls here

bool Stack::push(double value){
	if (top == maxStack){
		return false;
	}
	stack[top] = value;
	top ++;

	return true;
}

bool Stack::pop(double &value){	//pass by reference, will modify the argument
	if (top == 0){
		return false;
	}
	top--;
	value = stack[top];
	return true;
}

int Stack::getTop() const{	//Const makes the parameter const thus unmodifable
	return top;
}

int Stack::getMaxStack() const{
	return maxStack;
}

void Stack::print() const{
	cout << "Stack:" << endl;
	if (top == 0){
		cout << "Empty" << endl;
	}
	for (int i = 0; i < top; i++){
		cout << i << ":" << stack[i] << endl;
	}
	cout << "------" << endl;
}

Stack::~Stack(){
	delete [] stack;
}
