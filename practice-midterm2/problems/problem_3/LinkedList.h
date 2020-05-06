// DO NOT CHANGE OR EDIT ANYTHING IN THIS FILE
// Use this file for your reference.

struct ListNode {
	int value; // Node's value
	struct ListNode * next; // Pointer to next node in list
};

typedef struct ListNode ListNode;

struct LinkedList {
	ListNode * head; // head of linked list
};

typedef struct LinkedList LinkedList;

// function declarations
void llist_init(LinkedList * list);
void llist_print(LinkedList * list);
void llist_add(LinkedList * list, int value);
void llist_clear(LinkedList * list);
void llist_insert_first(LinkedList * list, int value);
int llist_number_elements(LinkedList * list);
void llist_insert_last(LinkedList * list, int value); 
int llist_remove_ith(LinkedList * list, int ith); 
void llist_sort(LinkedList * list, int value);
void llist_intersection(LinkedList * list1, LinkedList * list2, LinkedList * list3);
