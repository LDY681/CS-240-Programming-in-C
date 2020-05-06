
#include <stdlib.h>
#include <stdio.h>

// Simple list of integers
struct ListNode {
  int value;
  struct ListNode *next;
};

typedef struct ListNode ListNode;

struct ListNode *head = NULL;

void addFront(int val) {
	// Create new node
	ListNode * n = (ListNode *) malloc(sizeof(ListNode));
	n->value = val;
	
	// Add at the beginning of the list
	n->next = head;
	head = n;
}

void printList() {
	// Traverse list ad print elements
	printf("---List---\n");
	ListNode * n = head;
	while (n!=NULL) {
		printf("%d\n", n->value);
		n = n->next;
	}

}

int main()
{
	addFront(5);
	addFront(6);
	addFront(8);
	addFront(1);
	addFront(2);

	printList();
}

