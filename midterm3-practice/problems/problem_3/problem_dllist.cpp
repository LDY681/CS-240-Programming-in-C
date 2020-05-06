#include <iostream>
#include <string>
#include "DLList.h"

// Constructor
// DO NOT CHANGE
DLList::DLList() 
{
    head = new ListNode();
    head->next = head;
    head->prev = head;
}

// Prints the list
// DO NOT CHANGE
void DLList::print_list() 
{
    std::cout << "Printing List..." << std::endl;
    if ( head->next == head ) {
	std::cout << "Empty List" << std::endl;
    }
    else {
	ListNode * e = head->next;  
	while ( e != head) {
	    if ( e->next != head )
		std::cout << e->value << ", ";
	    else 
		std::cout << e->value;
	    e = e->next;
	}
	std::cout << std::endl;
    }
}

// Prints the list given a list name
// DO NOT CHANGE
void DLList::print_list( std::string list_name ) 
{
    std::cout << "Printing " << list_name << "..." << std::endl;
    if ( head->next == head ) {
	std::cout << "Empty List" << std::endl;
    }
    else {
	ListNode * e = head->next;  
	while ( e != head) {
	    if ( e->next != head )
		std::cout << e->value << ", ";
	    else 
		std::cout << e->value;
	    e = e->next;
	}
	std::cout << std::endl;
    }
}

// Problem (1/5)
/******************************************************************************
 * TODO: Write the destructor. The destructor should delete all of the 
 * list nodes from the list. 
 *****************************************************************************/
DLList::~DLList()
{
	//TODO£º
	delete head;
	ListNode::node_count = 0;
}

// Problem (2/5)
/******************************************************************************
 * TODO: Insert a new ListNode to the end of the double linked list. 
 * Remember the list head is a sentinel node, do not change head. 
 * Set the value of the new node to the parameter 'value'.
 * 
 * Parameters: value -- set the value of the node equal to this
 *
 * Return: void 
 *
 * Return Type: void
 *****************************************************************************/
void DLList::insert_last( int value ) 
{

		ListNode *e = new ListNode();
		e->value = value;
		e->next = head;
		e->prev = head->prev;
		head->prev = e;
		e->prev->next = e;
}

// Problem (3/5)
/******************************************************************************
 * TODO: Remove the node from the double linked list whose value equals the 
 * parameter 'value', return true after deleting the node. If the node does not
 * exist in the list or the list is empty, return false;
 * 
 * Parameters: value -- remove the node whose value is equal to this
 *
 * Return: true if the node was removed successfully
 *         false if the value does not exist in the list or the list is empty
 *
 * Return Type: void
 *****************************************************************************/
bool DLList::remove( int value ) 
{
	ListNode *e = head;
	int booll = 0;
	if (head -> next == head){
		return 0;
	}

	if ( head->next->next == head){
		head->prev = head;
		head->next = head;
		return 1;
	}

	while (e->next != head){
		if (e->value == value){
			booll = 1;
			//Normal
			e->prev->next = e->next;
			e->next->prev = e->prev;

		}
		e = e ->next;
	}
	if (booll == 1){
		return true;
	}
	return false;
}

// Problem (4/5)
/*****************************************************************************
* TODO: Return the ith node inside of the double linked list. If the list is
* empty or has less than 'ith' entries, return NULL.
* 
* Return: the 'ith' node in the list
*         NULL if the node does not exist
*
* Return Type:  
*****************************************************************************/
ListNode * DLList::get_ith( int ith ) 
{
	ListNode *e = head;
	if (ith < 0) return NULL;
	if (ListNode::node_count == 0){
		return NULL;
	}
	if (ith +1 >= ListNode::node_count ){
		return NULL;
	}
	int count = 0;
	while (1){
		if (count == ith +1 ) break;
		e = e->next;
		count++;
	}
	return e;
}

// Problem (5/5)
/*****************************************************************************
* TODO: Overload the operator '==' for comparison. The comparison operator
* should compare the two lists to check if they have the all of the same
* elements. Return true if the two lists are equal, return false otherwise.
*****************************************************************************/
bool DLList::operator == (const DLList & listB) 
{
	ListNode *nodea = head;
	ListNode *nodeb = listB.head;
	int count = 0;
	while (1){
		if (nodea->value != nodeb->value) return false;
		nodea = nodea->next;
		nodeb = nodeb->next;
		if (count > ListNode::node_count){
			break;
		}
		count++;
	}
    return true;
}
