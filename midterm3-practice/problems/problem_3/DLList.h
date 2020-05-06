#ifndef DLLIST_H
#define DLLISH_H
#include <stdio.h>
#include <iostream>

class ListNode {
    public:
	int value; 
	ListNode * next;
	ListNode * prev;
	static int node_count;
	ListNode() {
	    node_count++;
	}
	~ListNode() {
	    node_count--;
	}
	static void print_node_count() {
	    std::cout << "Node Count: " << node_count << std::endl;
	}
};

class DLList {
    private:
	ListNode * head;
    public:
	DLList();
	~DLList();
	void print_list();
	void print_list( std::string list_name );
	void insert_last( int value );
	bool remove( int value );
	ListNode * get_ith( int ith );
	bool operator == ( const DLList & listB );
};


#endif
