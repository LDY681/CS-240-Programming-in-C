#include "DLList.h"
#include <iostream>
/**
 * @brief      Constructor for the DLList.
 */

using namespace std;
DLList::DLList()
{
	/** @todo Write a constructor for a dllist. Check slides! **/
	head = new DLNode();
	head->next = head;
	head->prev = head;
}

/**
 * @brief      Destructor for the DLList.
 */
DLList::~DLList()
{
	/** @todo Clean up your mess! **/
	delete head;
}

/**
 * @brief      Print the DLList line by line.
 */
void DLList::print()
{
	/** @todo Print this list line by line **/
	DLNode *e = head->next;
	while (e  != head){
		cout << e->data << endl;
		e = e->next;
	}	
}

/**
 * @brief      Sort and print the list.
 * 
 * This function should sort and print the list.
 * Note: the actual list is NOT to be modified.
 * In other words, it should only *print* in a
 * sorted order, not actually sort the list.
 */
void DLList::printSorted()
{
	/** @todo Print a sorted copy of this list **/

	//Create a copy first
	DLList * sort = new DLList();
	DLNode *e = head->next;
	int length = 0;
	while ( e != head){
		sort->insertFront(e->data);
		e = e->next;
		length++;
	}

	//Start Sorting
	DLNode *p = sort->head->next;
	int counti = 0;
	while (counti < length){
		int countj = 0;
		while (countj < length - counti){
			DLNode *f = p;
			int i = 0;
			while (i < countj){
				f = f->next;
				i++;
			}
			if (p->data > f->data){
				int temp = p->data;
				p->data = f->data;
				f->data = temp;
			}
			countj++;
		}
		p = p->next;
		counti++;
	}

	/*
	DLNode *p = sort->head->next;

	while (p != sort->head){
		for (i = 0; i < count; i++){
			for ( j = 0; j < count - i; j++){
				if (p->data > p->next->data){
					DLNode * temp = p;
					p = p->next;
					p->next = temp;
					p->next->prev = p;
					p->prev->next = p;
				}
				p = p->next;
			}
		}
		
	}
	*/

	sort->print();
}

/**
 * @brief      Add to the front of the list.
 *
 * @param[in]  data  Item to add to front.
 */
void DLList::insertFront(int data)
{
	/** @todo Insert to the front of the list **/
	DLNode *e = new DLNode();
	e->data = data;
	e->next = head->next;
	e->prev = head;
	e->next->prev = e;
	e->prev->next = e;
}


/**
 * @brief      Removes & stores the last element.
 *
 * The last element is removed and stored in the
 * referenced variable data.
 * 
 * @param      data  Thing in which we are storing the data.
 *
 * @return     True upon successful removal.
 */
bool DLList::removeLast(int & data)
{
	/** @todo Remove the last thing **/
	DLNode *e = head->next;
	while (e->next != head){
		e = e->next;
	}

	e->prev->next = head;
	e->next->prev = e->prev;
	data = e->data;
	/*DLNode *temp = new DLNode();
	temp->data = data;
	
	temp->prev = e;
	temp->next = head;
	temp->prev->next = temp;
	temp->next->prev = temp;
	*/
}

/**
 * @brief      Difference of two lists.
 *
 * @param      list  Subtrahend.
 *
 * @return     Returns a pointer to the difference.
 */
DLList * DLList::difference(DLList & list)
{
	DLList * diff = new DLList();
	/** @todo Implement this function **/
	//list is the second list, and the first list would be "this"!!!
	
	int diffo = 1; // 0 = there isnt a difference, 1= this is a difference
	DLNode *e = this->head->next;
	while ( e != this->head ){
		DLNode *p = list.head->next;
			while( p != list.head){
				if ( e->data == p->data){
					diffo = 0;
					break;
				}
				p = p->next;
				diffo = 1;
			}
			if (diffo == 1){
				diff->insertFront(e->data);
			}
		e = e->next;
	}
	return diff;
}

/**
 * @brief      Returns a sublist of items in a range.
 *
 * @param[in]  start  First index.
 * @param[in]  end    Second index.
 *
 * @return     Elements between first and second index.
 */
DLList * DLList::getRange(int start, int end)
{
	DLList * range = new DLList();
	/** @todo getRange **/
	return range;
}

/**
 * @brief      Intersection of this list and another list.
 *
 * @param      list  The other list.
 *
 * @return     Elements list shares with this one.
 */
DLList * DLList::intersection(DLList & list)
{
	int store[10];
	int i = 0;
	DLList * diff = new DLList();
	/** @todo Implement this function **/
	//list is the second list, and the first list would be "this"!!!
	
	int diffo = 1; // 0 = there isnt a difference, 1= this is a difference
	DLNode *e = this->head->next;
	while ( e != this->head ){
		DLNode *p = list.head->next;
			while( p != list.head){
				if ( e->data == p->data){
					diffo = 0;
					break;
				}
				p = p->next;
				diffo = 1;
			}
			if (diffo == 0){
				store[i] = e->data;
				i++;
				//TODO:
			}
		e = e->next;
	}
	
	int j;
	for ( j = 0; j < i/2; j++){
		int temp = store[j];
		store[j] = store[i-j-1];
		store[i-j-1] = temp;
	}
		
	for ( j = 0; j < i; j++){
		diff->insertFront(store[j]);
	}
	return diff;
}

/**
 * @brief      Removes nodes in the start-end range.
 *
 * @param[in]  start  First node.
 * @param[in]  end    Second node.
 */
void DLList::removeRange(int start, int end)
{
	/** @todo Remove a range of elements **/
}
