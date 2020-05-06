
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

#include "rpn.h"
#include "nextword.h"
#include "stack.h"

double rpn_eval(char * fileName, double x) {
	double pop1, pop2, totalpop;
	FILE *fd;	//read the file
	char *word;	//each word, either a number or a operator
	double *stack[MAXSTACK];	//stack to store numbers

	//open file
	fd = fopen(fileName, "r");

	//check if word is a number or a expression
	while ( (word = nextword(fd)) != NULL ){	//while there is more word

		//if the word is a number

		//word length>1
		if(strlen(word) > 1){	
			//Condition1: word is a trigonal operator
			
			//string compare to see which operator it is 
			int sincmp = strcmp(word, "sin");
			int coscmp = strcmp(word, "cos");
			int powcmp = strcmp(word, "pow");
			int logcmp = strcmp(word, "log");
			int expcmp = strcmp(word, "exp");
			
			//Sin Opearator
			if(sincmp == 0){
				if (stack_top() < 1){	//Underflow check
					printf("Stack underflow\n");
					exit(1);
				}
			pop1 = stack_pop(stack);
			totalpop = sin(pop1);
			stack_push(totalpop);				
			}
			//Cos Opearator
			else if(coscmp == 0){
				if (stack_top() < 1){	//Underflow check
					printf("Stack underflow\n");
					exit(1);
				}
			pop1 = stack_pop(stack);
			totalpop = cos(pop1);
			stack_push(totalpop);				
			}
			//pow Opearator
			else if(powcmp == 0){
				if (stack_top() < 2){	//Underflow check
					printf("Stack underflow\n");
					exit(1);
				}
			pop1 = stack_pop(stack);
			pop2 = stack_pop(stack);
			totalpop = pow(pop2, pop1);
			stack_push(totalpop);				
			}
			//log Opearator
			else if(logcmp == 0){
				if (stack_top() < 1){	//Underflow check
					printf("Stack underflow\n");
					exit(1);
				}
			pop1 = stack_pop(stack);
			totalpop = log(pop1);
			stack_push(totalpop);				
			}
			//exp Opearator
			else if(expcmp == 0){
				if (stack_top() < 1){	//Underflow check
					printf("Stack underflow\n");
					exit(1);
				}
			pop1 = stack_pop(stack);
			totalpop = exp(pop1);
			stack_push(totalpop);				
			}
			else{	//Condition2: word is a number
			stack_push(atof(word)); //atof Convert string to double
			}
				
		}	//end of word length>1

		//word length=1 
		if(strlen(word) == 1){

			//Condition1: word is a number: >=0 && <=9 
			if(word[0] - '0' >= 0 && word[0] - '0' <= 9){
				stack_push(atof(word));
			}else if( 0 == strcmp(word, "x") ){	//word is x
				stack_push(x);
			}else{	

			//Condition2:word is a numerical operator

				//UnderFlow: if stack doesnt have enough elements to pop
				if (stack_top() < 2){	
					printf("Stack underflow\n");
					exit(1);
				}	//end of Underflow check

				pop1 = stack_pop(stack);
				pop2 = stack_pop(stack);

				//a to f, means string to floating point 
				//here we want string to integer, because switch expression takes integer or char 
				switch(word[0]){
					case '+' :
					totalpop =  pop2 + pop1;
					stack_push(totalpop);
					break;

					case '-' :
					totalpop = pop2 - pop1;
					stack_push(totalpop);
					break;

					case '*' :
					totalpop = pop2 * pop1;
					stack_push(totalpop);
					break;

					case '/' :
					totalpop = pop2/pop1;
					stack_push(totalpop);
					break;

				}	//end of switch
			}	//end of else(Condition 2: word is a numerical operator&length = 1)

		}	//end of word length = 1


	}	//end of while loop

	
	totalpop = stack_pop(stack);

	//check for errors
		//if stack is not empty
		if (!stack_is_empty()){
		printf("Elements remain in the stack\n");
		exit(1);
		}
	//return result
	return totalpop;
}
