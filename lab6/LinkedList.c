
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

//
// Initialize a linked list
//
void llist_init(LinkedList * list)
{
	list->head = NULL;
}

//
// It prints the elements in the list in the form:
// 4, 6, 2, 3, 8,7
//
void llist_print(LinkedList * list) {
	
	ListNode * e;

	if (list->head == NULL) {
		printf("{EMPTY}\n");
		return;
	}

	printf("{");

	e = list->head;
	while (e != NULL) {
		printf("%d", e->value);
		e = e->next;
		if (e!=NULL) {
			printf(", ");
		}
	}
	printf("}\n");
}

//
// Appends a new node with this value at the beginning of the list
//
void llist_add(LinkedList * list, int value) {
	// Create new node
	ListNode * n = (ListNode *) malloc(sizeof(ListNode));
	n->value = value;
	
	// Add at the beginning of the list
	n->next = list->head;
	list->head = n;
}

//
// Returns true if the value exists in the list.
//
int llist_exists(LinkedList * list, int value) {
	ListNode *e;
	e = list->head;
	while (e != NULL){
		if (e->value == value){
			return 1;
		}
		e = e->next;
	}
	return 0;
}

//
// It removes the entry with that value in the list.
//
int llist_remove(LinkedList * list, int value) {
	if (!llist_exists(list, value)){
		return 0;
	}
	
	//Initialize
	ListNode *prev, *e;
	prev = NULL;
	e = list->head;

	while (e != NULL){
		if (e->value == value){
		
			//First element condition
			if (prev == NULL){
			list->head = e->next;
			free(e);
			}

			//Normal condition
			prev->next = e->next;
			free(e);
		}
		prev = e;
		e = e->next;	
	}
	

	return 1;
}

//
// It stores in *value the value that correspond to the ith entry.
// It returns 1 if success or 0 if there is no ith entry.
//
int llist_get_ith(LinkedList * list, int ith, int * value) {
	int count = 0;
	ListNode *e = list->head;
	while (e != NULL){
			if (count == ith){
			*value = e->value;
			return 1;
		}
		e = e->next;
		count++;
	}
	return 0;
}

//
// It removes the ith entry from the list.
// It returns 1 if success or 0 if there is no ith entry.
//
int llist_remove_ith(LinkedList * list, int ith) {
	int count = 0;
	ListNode *e, *prev;
	e = list->head;
	prev = NULL;
	while (e != NULL){
		if (count == ith){
			prev->next = e->next;
			free(e);
			return 1;	
		}
		prev = e;
		e = e->next;
		count++;
	}
	return 0;
}

		//
// It returns the number of elements in the list.
//
int llist_number_elements(LinkedList * list) {
	int count = 0;
	ListNode *e = list->head;
	while (e != NULL){
		count++;
		e = e->next;
	}
	return count;
}


//
// It saves the list in a file called file_name. The format of the
// file is as follows:
//
// value1\n
// value2\n
// ...
//
int llist_save(LinkedList * list, char * file_name) {

	FILE *fp;
	fp = fopen(file_name,"w+");	//open and write the file with filename
	
	//if file doesnt exist
	if (fp == NULL){
		return 0;
	}
		

	int count = 0;
	ListNode *e = list->head;
	
	while (e != NULL){
		char* store = (char*) malloc(100 * sizeof(char));
		sprintf(store, "%d\n", e->value);
		
		fprintf(fp, "%d\n", e->value);
		//fwrite(store,1,sizeof(store),fp);	
		e = e->next;		
		count++;
	}
	fclose(fp);
	return 0;
}

//
// It reads the list from the file_name indicated. If the list already has entries, 
// it will clear the entries.
//
int llist_read(LinkedList * list, char * file_name) {
	ListNode *e = list->head;

	FILE *fp;
	fp = fopen(file_name,"rb");	//open and write the file with filename
	
	//if file doesnt exist
	if (fp == NULL){
		return 1;
	}

	fseek(fp, 0, SEEK_END);

	char mystring [100];
	while (fgets(mystring, 100, fp) != NULL){
		e->value = atoi(mystring);
		e=e->next;
	}
	
	return 1;	
}


//
// It sorts the list. The parameter ascending determines if the
// order si ascending (1) or descending(0).
//
void llist_sort(LinkedList * list, int ascending) {

}

//
// It removes the first entry in the list and puts value in *value.
// It also frees memory allocated for the node
//
int llist_remove_first(LinkedList * list, int * value) {

	if (list->head == NULL){
		return 0;
	}
	ListNode *e = list->head;
	list->head = e->next;
	*value = e->value;
	free(e);
	return 1;
}

//
// It removes the last entry in the list and puts value in *value/
// It also frees memory allocated for node.
//
int llist_remove_last(LinkedList * list, int *value) {
	if (list->head == NULL){
		return 0;
	}
	//Initialize
	ListNode *prev, *e;
	prev = NULL;
	e = list->head;

	while (e->next != NULL){
		prev = e;
		e = e->next;	
	}
	*value = prev->next->value;
	free(prev->next);
	prev->next = NULL;


	return 1;
}

//
// Insert a value at the beginning of the list.
// There is no check if the value exists. The entry is added
// at the beginning of the list.
//
void llist_insert_first(LinkedList * list, int value) {
	// Create new node
	ListNode * n = (ListNode *) malloc(sizeof(ListNode));
	n->value = value;
	
	// Add at the beginning of the list
	n->next = list->head;
	list->head = n;
}

//
// Insert a value at the end of the list.
// There is no check if the name already exists. The entry is added
// at the end of the list.
//
void llist_insert_last(LinkedList * list, int value) {
	ListNode *e, *prev;
       	e = list->head;
	
	if (e == NULL){
		e->value = value;
		e->next = NULL;
		return;
	}
	while (e != NULL){
		prev = e;
		e = e->next;
	}
	ListNode * n = (ListNode *) malloc(sizeof(ListNode));
	n->value = value;
	n->next = NULL;
	prev->next = n;
}

//
// Clear all elements in the list and free the nodes
//
void llist_clear(LinkedList *list){
	ListNode *e, *next;
       	e = list->head;
	while (e != NULL){
		next = e->next;
		free(e);
		e = next;
	}
	list->head = NULL;
}
