
#include "DLList.h"
#include <iostream>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

void test1()
{

	DLList list;
	list << 1 << 2 << 12 << 13 << 11 << 22;
	std::cout<<"List:"<<std::endl;
	list.print();
}

void test2()
{
	DLList list1; DLList list2;
	list1 << 12 << 2222 << 123 << 12;
	list2 << 11 << 1 << 123 << 2 << 12;

	std::cout<<"List 1:"<<std::endl;
	list1.print();
	std::cout<<std::endl;

	std::cout<<"List 2:"<<std::endl;
	list2.print();
	std::cout<<std::endl;

	std::cout<<"List 1 - List 2"<<std::endl;
	(list1 - list2).print();
	std::cout<<std::endl;

	std::cout<<"List 2 - List 1"<<std::endl;
	(list2 - list1).print();
}

void test3()
{
	DLList list; int dave;
	list << 1 << 1 << 1 << 0 << 0 << 12 << 123123;

	std::cout<<"List:"<<std::endl;
	list.print();

	std::cout<<std::endl<<"Removing last index..."<<std::endl<<std::endl;
	std::cout<<"List:"<<std::endl;
	bool saved = list.removeLast(dave);
	list.print(); std::cout<<std::endl;

	std::cout<<"Removed element: "<<dave<<std::endl;
	std::cout<<"Success? "<<((saved) ? "Yes." : "No.")<<std::endl;
}

void test4()
{
	DLList list;
	list << 1 << 1 << 2 << 3 << 5 << 8 << 13 << 21 << 34 << 55 << 89;

	std::cout<<"List:"<<std::endl;
	list.print();

	std::cout<<std::endl<<"Sorted list:"<<std::endl;
	list.printSorted();

	std::cout<<std::endl<<"List:"<<std::endl;
	list.print();
}

void test5()
{
	DLList list1, list2;
	for (int x = 0; x < 100; ++x) {
		if (x % 4 == 0)
			list1 << x;
		if (x % 5 == 0)
			list2 << x;
	}

	std::cout<<"List1:"<<std::endl;
	list1.print(); std::cout<<std::endl;

	std::cout<<"List2:"<<std::endl;
	list2.print(); std::cout<<std::endl;

	std::cout<<"Intersection:"<<std::endl;
	DLList * intersect = list1.intersection(list2);
	intersect->print(); delete intersect;
}

int main(int argc, char ** argv)
{
	if (argc < 2) {
		std::cout<<"test_mysort [test1|test2|test3|test4|test5]"<<std::endl;
		return 2;
	}

	if (strcmp(argv[1],"test1")==0) {
		test1();
	} else if (strcmp(argv[1],"test2")==0) {
		test2();
	} else if (strcmp(argv[1],"test3")==0) {
		test3();
	} else if (strcmp(argv[1],"test4")==0) {
		test4();
	} else if (strcmp(argv[1],"test5")==0) {
		test5();
	} else {
		std::cout<<"Invalid test number."<<std::endl;
		return 1;
	}

	return 0;
}
