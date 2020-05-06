
#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

//top "keeps track of the top element in the stack"
//never do instructions like that, so confusing!

int top=0;	//How many elements in stack
double stack[MAXSTACK];


void stack_clear() {
  top = 0;
}

//Get the element from top of the stack
//Update stack to the nest top element
double stack_pop(){
	//If no elements in stack(top is 0)
	if (top > 0){
		double ret = stack[top - 1];	// top - 1 is the location of the top element
		--top;	//One less element in stack, decrement top 
		return ret;
	}
	return 0;
}

//push val to the most right of the stack before the other element 
void stack_push(double val){
	//If not reaching the max stacks
	if ( top != MAXSTACK){
		stack[top] = val;
		++top;
		
	}
}

//Print stacks
void stack_print(){
	printf("Stack:\n");

	//If stack is empty
	if (top == 0){
		printf("Stack is empty");
	}

	//If not
	int i;
	for (i = 0; i < top; ++i){
		printf("%d: %lf\n", i, stack[i]);
	}	
}

int stack_top()
{
  return top;
}

int stack_max()
{
  return MAXSTACK;
}

int stack_is_empty()
{
  return top == 0;
}


