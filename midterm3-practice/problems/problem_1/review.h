#ifndef REVIEW_H
#define REVIEW_H

// ListNode of single linked list
typedef struct ListNode {
    int value;
    struct ListNode * next;
} ListNode;

// Single Linked List
typedef struct List {
    ListNode * head;
} List;

// Function Declerations
extern char * strchr(const char *s, int c);
int max_array(int * array, int n);
int get_bit_at(unsigned int bitmap, int ith);
List * llist_read( char * filename );
void llist_init( List * list);
void llist_print( List * list );
void llist_clear( List * list );
void llist_add( List * list, int value );
#endif
