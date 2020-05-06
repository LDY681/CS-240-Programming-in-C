
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "LinkedList.h"

void test1() {
	LinkedList list;

	llist_init(&list);

	llist_print(&list);

	llist_add(&list,2);
	llist_add(&list,5);
	llist_add(&list,6);

	llist_print(&list);

}

void test2() {
	LinkedList list;
	
	llist_init(&list);

	llist_print(&list);

	llist_add(&list,2);
	llist_add(&list,5);
	llist_add(&list,6);

	llist_print(&list);

	llist_add(&list,1);
	llist_add(&list,4);
	llist_add(&list,8);

	llist_print(&list);

	int result = llist_exists(&list, 4);
	printf("4 exists=%d\n", result);

	result = llist_exists(&list, 11);
	printf("11 exists=%d\n", result);
}

void test3() {
	int i;
	LinkedList list;

	llist_init(&list);
	llist_print(&list);

	for (i=0; i < 30; i++) {
		printf("Adding %d\n", i);
		llist_add(&list, i);
	}
	llist_print(&list);

}

void test4() {
	int i = 0;
	int result;
	LinkedList list;

	llist_init(&list);

	llist_print(&list);

	for (i=0; i < 30; i++) {
		printf("Adding %d\n", i);
		llist_add(&list, i);
	}

	llist_print(&list);

	printf("remove 5\n");
	result = llist_remove(&list, 5);
	printf("result1=%d\n", result);

	llist_print(&list);

	printf("remove 18\n");
	result = llist_remove(&list, 18);
	printf("result2=%d\n", result);

	llist_print(&list);

	printf("remove 64\n");
	result = llist_remove(&list, 64);
	printf("result3=%d\n", result);

	llist_print(&list);
}

void test5() {
	int i = 0;
	int result;
	LinkedList list;
	int value;

	llist_init(&list);

	llist_print(&list);

	for (i=0; i < 30; i++) {
		printf("Adding %d\n", i+3);
		llist_add(&list, i+3);
	}

	llist_print(&list);

	// Get 11th value
	printf("Get 11th entry\n");
	result = llist_get_ith(&list, 11, &value);
	printf("For 11th value value=%d\n", value);
	printf("result1=%d\n", result);

	// Get 23th value
	printf("Lookup 23th entry\n");
	result = llist_get_ith(&list, 23, &value);
	printf("For 23th value=%d\n", value);
	printf("result2=%d\n", result);

	// Get 64th value
	printf("Lookup 64th entry\n");
	result = llist_get_ith(&list, 64, &value);
	printf("result3=%d\n", result);
}

void test6() {
	int i = 0;
	int result;
	LinkedList list;

	llist_init(&list);
	llist_print(&list);

	for (i=0; i < 30; i++) {
		printf("Adding %d\n", i+3);
		llist_add(&list, i+3);
	}
	llist_print(&list);

	printf("remove value in position 5\n");
	result = llist_remove_ith(&list, 5);
	printf("result1=%d\n", result);

	llist_print(&list);

	printf("remove name in position 23\n");
	result = llist_remove_ith(&list, 23);
	printf("result2=%d\n", result);

	llist_print(&list);

	printf("remove name in position 67\n");
	result = llist_remove_ith(&list, 67);
	printf("result3=%d\n", result);

	llist_print(&list);
}


void test7() {
	int i = 0;
	int result;
	LinkedList list;

	llist_init(&list);
	llist_print(&list);

	for (i=0; i < 30; i++) {
		printf("Adding %d\n", i+3);
		llist_add(&list, i+3);
	}
	llist_print(&list);

	printf("# elements in table: %d\n", llist_number_elements(&list));
}

void test8() {
	int i = 0;
	int result;
	LinkedList list;

	system("rm -f mytable.ll");

	llist_init(&list);
	llist_print(&list);

	for (i=0; i < 30; i++) {
		printf("Adding %d\n", i+3);
		llist_add(&list, i+3);
	}
	llist_print(&list);

	printf("Saving table /notallowed\n");
	result = llist_save(&list, "/notallowed");
	printf("result1=%d\n", result);

	printf("Saving table mytable1.ll\n");
	result = llist_save(&list, "mytable.ll");
	printf("result2=%d\n", result);

	printf("----- cat mytable.ll -----\n");
	system("cat mytable.ll");
}

void test9() {
	int result;
	LinkedList list;

	llist_init(&list);
	llist_print(&list);

	printf("Read non existing table\n");
	result = llist_read(&list, "nonexsting.rt");
	printf("result1=%d\n", result);

	printf("Read table1.ll\n");
	result = llist_read(&list, "table1.ll");
	printf("result2=%d\n", result);

	llist_print(&list);
}

void test10() {
	int result;
	LinkedList list;

	llist_init(&list);
	llist_print(&list);

	printf("Read table1.ll\n");
	result = llist_read(&list, "table1.ll");
	printf("result2=%d\n", result);

	llist_print(&list);

	printf("\nSort ascending\n");
	llist_sort(&list,1);
	llist_print(&list);

	printf("\nSort descending\n");
	llist_sort(&list,0);
	llist_print(&list);
}

void test11() {
	int i = 0;
	int result;
	int value;
	LinkedList list;

	llist_init(&list);
	llist_print(&list);

	result = llist_remove_first(&list, &value);
	printf("llist_remove_first result=%d \n", result);

	result = llist_remove_last(&list, &value);
	printf("llist_remove_last result=%d\n", result);
	
	for (i=0; i < 30; i++) {
		printf("Adding %d\n", i+3);
		llist_add(&list, i+3);
	}
	llist_print(&list);

	// Remove from one side or the other
	for (i=0; i < 10; i++) {
	  result = llist_remove_first(&list, &value);
	  printf("llist_remove_first result=%d value=%d\n", result, value);
	}

	llist_print(&list);

	for (i=0; i < 10; i++) {
	  result = llist_remove_last(&list, &value);
	  printf("llist_remove_last result=%d value=%d\n", result, value);
	}

	llist_print(&list);
	
	llist_clear(&list);

	llist_print(&list);
}

void test12() {
	int i = 0;
	int result;
	LinkedList list;

	llist_init(&list);
	llist_clear(&list);
	llist_print(&list);

	for (i=0; i < 30; i++) {
		printf("Adding %d\n", i);
		llist_add(&list,i);
	}
	llist_print(&list);

	for (i=40; i < 50; i++) {
		printf("Adding first %d\n", i);
		llist_insert_first(&list, i);
	}
	llist_print(&list);

	for (i=50; i < 60; i++) {
		printf("Adding %d\n", i);
		llist_insert_last(&list, i);
	}
	llist_print(&list);
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
	else if (strcmp(test, "test9")==0) {
		test9();
	}
	else if (strcmp(test, "test10")==0) {
		test10();
	}
	else if (strcmp(test, "test11")==0) {
		test11();
	}
	else if (strcmp(test, "test12")==0) {
		test12();
	}
	else {
		printf("Test not found!!n");
		exit(1);
	}

	return 0;
}

