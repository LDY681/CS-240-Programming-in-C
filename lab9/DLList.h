#ifndef DL_LIST_H
#define DL_LIST_H
#include <iostream>
#include <algorithm>

struct DLNode {
	int data;
	DLNode * next;
	DLNode * prev;
};

class DLList {
public:
	DLList();
	~DLList();
	void print();
	void printSorted();

	void insertFront(int data);
	bool removeLast(int & data);
	DLList * difference(DLList & list);
	DLList * getRange(int start, int end);
	DLList * intersection(DLList & list);
	void removeRange(int start, int end);
	/**
	 * @brief      This operator does insert front.
	 * 
	 * Please, please, please do not remove it or change it.
	 * This is for testing purposes only.
	 *
	 * @param[in]  data  Thing to insert front.
	 *
	 * @return     Returns a reference to this.
	 */
	DLList & operator << (int data) {
		this->insertFront(data);
		return *this;
	}

	/**
	 * @brief      This operator does subtraction.
	 * 
	 * Please, please, please do not remove or change this code.
	 * This is for testing purposes only.
	 *
	 * @param      other  List to remove.
	 *
	 * @return     *this - other
	 */
	DLList & operator - (DLList & other) {
		return *difference(other);
	}

private:
	DLNode * head;
};
#endif
