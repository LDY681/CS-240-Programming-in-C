#ifndef POINTER_TO_FUNCTION_H
#define POINTER_TO_FUNCTION_H

typedef struct student {
	char * firstName;
	char * lastName;
	char * major;
	char grade;
	int id;
} student;

typedef int (*MatchesFunc) (int key, void * element);

int findElement(int n, int elementSize, void * array, int key, void * result, MatchesFunc matches);

#endif
