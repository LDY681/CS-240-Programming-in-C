#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

// Test Functions
void test1()
{
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

void test2()
{
    int i = 0;
    int result;
    LinkedList list;

    llist_init(&list);
    llist_clear(&list);
    llist_print(&list);

    for (i=0; i < 20; i++) {
	printf("Inserting Last %d\n", i);
	llist_insert_last(&list, i);
    }
    llist_print(&list);
}

void test3()
{
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

    printf("remove value in position 5\n");
    result = llist_remove_ith(&list, 5);
    printf("result1=%d\n", result);

    llist_print(&list);

    printf("remove value in position 23\n");
    result = llist_remove_ith(&list, 23);
    printf("result2=%d\n", result);

    llist_print(&list);

    printf("remove value in position 67\n");
    result = llist_remove_ith(&list, 67);
    printf("result3=%d\n", result);

    llist_print(&list);
}

void test4()
{
    LinkedList list1;
    llist_init(&list1);

    int i;

    for (i = 30; i >= 0; i=i-3) {
	llist_add(&list1, i);
    }
    printf("List 1\n");
    llist_print(&list1);

    LinkedList list2;
    llist_init(&list2);

    for (i = 30; i >= 0; i=i-5) {
	llist_add(&list2, i);
    }

    printf("List 2\n");
    llist_print(&list2);

    LinkedList list3;
    llist_init(&list3);
    printf("Intersection of List 1 and List 2\n");
    llist_intersection(&list1, &list2, &list3);
    llist_sort(&list3, 1);
    llist_print(&list3);	
}

int main(int argc, char ** argv) {

  char * test;
  
  if (argc <2) {
    printf("Usage: test_array test1|test2|test3|test4|test5|test6\n");
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
  else {
    printf("Test not found!\n");
    exit(1);
  }
  
  return 0;
}

