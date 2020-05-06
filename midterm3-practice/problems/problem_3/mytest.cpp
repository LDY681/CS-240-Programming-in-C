#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "DLList.h"

int ListNode::node_count = 0;

void test1() {
    DLList list;
    list.insert_last( 9 );
    list.insert_last( 21 );
    list.insert_last( 8 );
    list.insert_last( 35 );
    list.insert_last( 3 );
    list.insert_last( 15 );
    list.print_list();
}

void test2() {
    DLList list1;
    list1.insert_last( 5 );
    list1.insert_last( 1 );
    list1.insert_last( 13 );
    list1.insert_last( 2 );
    list1.print_list("List1");

    std::cout << std::endl;

    DLList * list2 = new DLList();
    list2->insert_last( 38 );
    list2->print_list("List2");

    std::cout << std::endl;

    DLList * list3 = new DLList();
    list3->print_list("List3");

    delete list2;
    delete list3;
}

void test3() {
    DLList list;
    for (int i = 0; i < 10; i++) {
	list.insert_last( i );
    }
    list.print_list();
    std::cout << std::endl;

    bool b = list.remove( 8 );
    std::cout << "Removed 8: " << b << std::endl;
    list.print_list();
    std::cout << std::endl;

    b = list.remove( 11 );
    std::cout << "Removed 11: " << b << std::endl;
    list.print_list();
    std::cout << std::endl;

    b = list.remove( 3 );
    std::cout << "Removed 3: " << b << std::endl;
    list.print_list();
    std::cout << std::endl;

    b = list.remove( 73 );
    std::cout << "Removed 73: " << b << std::endl;
    list.print_list();
    std::cout << std::endl;

    b = list.remove( 1 );
    std::cout << "Removed 1: " << b << std::endl;
    list.print_list();
}

void test4() {
    DLList listA;
    for (int i = 4; i >= 0; i--) {
	listA.insert_last( i );
    }
    for (int i = 5; i >= -1; i--) {
	bool b = listA.remove( i );
	std::cout << "Removed " << i << ": " << b << std::endl;
	listA.print_list();
	if ( i != -1 )
	    std::cout << std::endl;
    }
}

void test5() {
    DLList * list = new DLList();
    for (int i = 0; i < 20; i++) {
	list->insert_last( i*i );
    }
    list->print_list();

    for (int i = 0; i < 11; i++) {
	ListNode * e = list->get_ith(i + i);
	if ( e == NULL) {
	    printf("get_ith(%d)=NULL\n", i+i);
	}
	else {
	    printf("get_ith(%d)=%d\n", i+i, e->value);
	}
    }
    delete list;
}

void test6() {
    DLList list;
    list.print_list();
    ListNode * e = list.get_ith(0);
    if ( e == NULL) {
	printf("get_ith(%d)=NULL\n", 0);
    }
    else {
	printf("get_ith(%d)=%d\n", 0, e->value);
    }
}

void test7() {
    DLList list;
    list.print_list();
    ListNode * e = list.get_ith(0);
    if ( e == NULL) {
	printf("get_ith(%d)=NULL\n", 0);
    }
    else {
	printf("get_ith(%d)=%d\n", 0, e->value);
    }

    for (int i = -10; i < 11; i++) {
	list.insert_last( i + i );
    }
    list.print_list();
    
    for (int i = -11; i < 12; i++) {
	e = list.get_ith( i + i + 1);
	if ( e == NULL) {
	    printf("get_ith(%d)=NULL\n", i+i+1);
	}
	else {
	    printf("get_ith(%d)=%d\n", i+i+1, e->value);
	}
    }

}

void test8() {
    // Test for memory leaks
    DLList * listA = new DLList();
    listA->insert_last( 2 );
    listA->insert_last( 3 );
    listA->insert_last( 5 );
    listA->insert_last( 7 );
    listA->insert_last( 11 );
    listA->insert_last( 13 );
    listA->insert_last( 17 );
    listA->insert_last( 19 );
    listA->print_list( "List A" );
    ListNode::print_node_count();
    std::cout << "Deleting List..." << std::endl;
    delete listA;
    ListNode::print_node_count();

    std::cout << std::endl;

    DLList * listB = new DLList();
    listA->insert_last( 23 );
    listA->insert_last( 29 );
    listA->print_list( "List B" );
    ListNode::print_node_count();
    std::cout << "Deleting List..." << std::endl;
    delete listB;
    ListNode::print_node_count();
}

void test9() {
    DLList listA;
    listA.insert_last( 5 );
    listA.insert_last( 10 );
    listA.insert_last( 15 );
    listA.print_list("listA");

    DLList listB;
    listB.insert_last( 5 );
    listB.insert_last( 10 );
    listB.insert_last( 15 );
    listB.print_list("listB");

    DLList listC;
    listC.insert_last( 5 );
    listC.insert_last( 25 );
    listC.insert_last( 55 );
    listC.print_list("listC");

    bool b = listA==listB;
    std::cout << "(listA == listB)=" << b << std::endl;
    b = listA == listA; 
    std::cout << "(listA == listA)=" << b << std::endl;
    b = listA == listC;
    std::cout << "(listA == listC)=" << b << std::endl;
    b = listB == listC;
    std::cout << "(listB == listC)=" << b << std::endl;

}

int main( int argc, char ** argv ) {
    if (argc <2) {
	std::cout << "Usage: mytest test1|test2|test3|test4| ..." << std::endl; 
	exit(1);
    }

    std::string test = argv[1];;

    if ( test == "test1" ) {
	test1();
    }
    else if ( test == "test2" ) {
	test2();
    }
    else if ( test == "test3" ) {
	test3();
    }
    else if ( test == "test4" ) {
	test4();
    }
    else if ( test == "test5" ) {
	test5();
    }
    else if ( test == "test6" ) {
	test6();
    }
    else if ( test == "test7" ) {
	test7();
    }
    else if ( test == "test8" ) {
	test8();
    }
    else if ( test == "test9" ) {
	test9();
    }
    else {
	std::cout << "Test Not Found!" << std::endl;
	exit(1);
    }
    return 0;
}
