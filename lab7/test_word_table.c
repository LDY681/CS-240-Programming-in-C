
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "WordTable.h"

void test1() {
	WordTable wtable;

	wtable_init(&wtable);
	wtable_add(&wtable, "Hello", 1);
	wtable_add(&wtable, "World", 10);
	wtable_print(&wtable, stdout);
}

void test2() {
	WordTable wtable;

	wtable_init(&wtable);
	wtable_add(&wtable, "Hello", 1);
	wtable_add(&wtable, "World", 10);
	wtable_add(&wtable, "Hello", 11);
	wtable_add(&wtable, "World", 12);
	wtable_add(&wtable, "Hello", 16);
	wtable_add(&wtable, "World", 19);
	wtable_add(&wtable, "Hello", 21);
	wtable_add(&wtable, "World", 22);
	wtable_print(&wtable, stdout);
}

void test3() {
	WordTable wtable;

	wtable_init(&wtable);
	int result = wtable_createFromFile(&wtable, "noneexisting", 1);
	printf("result nonexsiting=%d\n", result);

	result = wtable_createFromFile(&wtable, "cosmos.txt", 1);
	printf("result =%d\n", result);
	
}

void test4() {
	WordTable wtable;

	wtable_init(&wtable);
	int result = wtable_createFromFile(&wtable, "sagan.txt", 1);
	printf("result =%d\n", result);

	wtable_print(&wtable, stdout);
	
}

void test5() {
	WordTable wtable;

	wtable_init(&wtable);
	int result = wtable_createFromFile(&wtable, "sagan.txt", 1);
	wtable_sort(&wtable);
	wtable_print(&wtable, stdout);
	
}

void test6() {
	WordTable wtable;

	wtable_init(&wtable);
	int result = wtable_createFromFile(&wtable, "sagan.txt", 0);
	wtable_sort(&wtable);
	wtable_textSegments(&wtable, "human", "sagan.txt");
}

void test7() {
	WordTable wtable;

	wtable_init(&wtable);
	int result = wtable_createFromFile(&wtable, "sagan.txt", 0);
	wtable_sort(&wtable);
	wtable_textSegments(&wtable, "star", "sagan.txt");
}
void test8() {
	WordTable wtable;

	wtable_init(&wtable);
	int result = wtable_createFromFile(&wtable, "sagan.txt", 0);
	wtable_sort(&wtable);
	wtable_textSegments(&wtable, "atoms", "sagan.txt");
}

int main(int argc, char ** argv) {

	char * test;
	
	if (argc <2) {
		printf("Usage: test_linked_list test1|test2|...test12\n");
		exit(1);
	}

	test = argv[1];

	printf("Running %s\n", test);

	if (strcmp(test, "test1")==0) {
		test1();
	}
	else if (strcmp(test, "test2")==0) {
		test2();
	}
	else if (strcmp(test, "test3")==0) {
		test3();
	}
	else if (strcmp(test, "test4")==0) {
		test4();
	}
	else if (strcmp(test, "test5")==0) {
		test5();
	}
	else if (strcmp(test, "test6")==0) {
		test6();
	}
	else if (strcmp(test, "test7")==0) {
		test7();
	}
	else if (strcmp(test, "test8")==0) {
		test8();
	}
	else {
		printf("Test not found!!n");
		exit(1);
	}
}

