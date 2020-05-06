#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "review.h"

void llist_init( List * list ) {
    list->head = NULL;
}

void llist_print( List * list ) {
    printf("Printing List...\n");
    if (list->head == NULL) {
	printf("{Empty}\n");
	return;
    }
    ListNode *e = list->head;
    while ( e->next != NULL ) {
	printf("%d->", e->value);
	e = e->next;
    }
    printf("%d\n", e->value);
}

void llist_clear( List * list ) {
    while ( list->head != NULL ) {
	ListNode *e = list->head->next;
	free(list->head);
	list->head = e;
    }
}

void llist_add( List * list, int value ) {
    if ( list->head == NULL ) {
	list->head = (ListNode *) malloc(sizeof(ListNode));
	list->head->value = value;
	list->head->next = NULL;
	return;
    }
    ListNode * e = list->head;
    while ( e->next != NULL ) {
	e = e->next;
    }
    ListNode * new_node = (ListNode *) malloc(sizeof(ListNode));
    new_node->value = value;
    new_node->next = NULL;
    e->next = new_node;
}


void print_bits( unsigned int x ) {
    for (int i = (sizeof(x) * 8) - 1; i >= 0; i--) {
	printf("%d", (x >> i) & 1);
    }
    puts("");
}

void test1() {
    char * str = "stop, drop, roll";
    char c = 'd';
    char * ptr =strchr( str , c );
    printf("strchr(\"%s\", \'%c\')=\"%s\"\n", str, c, ptr); 
}

void test2() {
    char * str = "abcdefghijklmnoqrstuvwxyz";
    char c = 'm';
    char * ptr =strchr( str , c );
    printf("strchr(\"%s\", \'%c\')=\"%s\"\n", str, c, ptr); 

    str = "test";
    c = 'r';
    ptr =strchr( str , c );
    printf("strchr(\"%s\", \'%c\')=\"%s\"\n", str, c, ptr); 

    str = "dog";
    c = 'd';
    ptr =strchr( str , c );
    printf("strchr(\"%s\", \'%c\')=\"%s\"\n", str, c, ptr); 

    str = "corn";
    c = 'I';
    ptr =strchr( str , c );
    printf("strchr(\"%s\", \'%c\')=\"%s\"\n", str, c, ptr); 
}

void test3() {
    int array [] = {1, 2, 3, 4, 5};
    int n = sizeof(array)/sizeof(int);
    printf("array={1, 2, 3, 4, 5}\n");
    printf("array max=%d\n", max_array(array,n));
}

void test4() {
    int array [] = {-1, -35, -45, -6};
    int n = sizeof(array)/sizeof(int);
    printf("array={-35, -1, -45, -6}\n");
    printf("array max=%d\n", max_array(array,n));

    puts("");

    int array2 [] = {1500, 500, 1000, 3, 2};
    n = sizeof(array2)/sizeof(int);
    printf("array2={1500, 500, 1000, 3, 2}\n");
    printf("array2 max=%d\n", max_array(array2,n));

    puts("");

    int array3 [] = {-30, -2000, 15};
    n = sizeof(array3)/sizeof(int);
    printf("array3={-30, -2000, 15}\n");
    printf("array3 max=%d\n", max_array(array3,n));
}

void test5() {
    unsigned int a = 2037;
    printf("a:\n");
    print_bits( a );
    printf("get_bit_at(%u, %d)=%d\n", a, 5, get_bit_at(a, 5));
    printf("get_bit_at(%u, %d)=%d\n", a, 3, get_bit_at(a, 3));
    printf("get_bit_at(%u, %d)=%d\n", a, 0, get_bit_at(a, 0));
    printf("get_bit_at(%u, %d)=%d\n", a, 1, get_bit_at(a, 1));
}

void test6() {
    unsigned int a = 255;
    printf("a:\n");
    print_bits( a );
    printf("get_bit_at(%u, %d)=%d\n", a, 9, get_bit_at(a, 9));
    printf("get_bit_at(%u, %d)=%d\n", a, 2, get_bit_at(a, 2));
    printf("get_bit_at(%u, %d)=%d\n", a, 3, get_bit_at(a, 3));
    printf("get_bit_at(%u, %d)=%d\n", a, 21, get_bit_at(a, 21));

    puts("");

    unsigned int b = 213653;
    printf("b:\n");
    print_bits( b );
    printf("get_bit_at(%u, %d)=%d\n", b, 9, get_bit_at(b, 9));
    printf("get_bit_at(%u, %d)=%d\n", b, 2, get_bit_at(b, 2));
    printf("get_bit_at(%u, %d)=%d\n", b, 3, get_bit_at(b, 3));
    printf("get_bit_at(%u, %d)=%d\n", b, 21, get_bit_at(b, 21));

    puts("");

    unsigned int c = 2679189;
    printf("c:\n");
    print_bits( c );
    printf("get_bit_at(%u, %d)=%d\n", c, 10, get_bit_at(c, 10));
    printf("get_bit_at(%u, %d)=%d\n", c, 3, get_bit_at(c, 3));
    printf("get_bit_at(%u, %d)=%d\n", c, 31, get_bit_at(c, 31));
    printf("get_bit_at(%u, %d)=%d\n", c, 0, get_bit_at(c, 0));
}

void test7() {
    char * filename = "files/file1.txt";
    List * list = llist_read( filename );    
    llist_print( list );
    llist_clear( list );
}

void test8() {
    char * filename = "files/file1.txt";
    List * list = llist_read( filename );    
    llist_print( list );
    llist_clear( list );

    puts("");

    char * filename2 = "files/file2.txt";
    List * list2 = llist_read( filename2 );    
    llist_print( list2 );
    llist_clear( list2 );
}

int main(int argc, char ** argv) {

    char * test;

    if (argc < 2) {
	printf("Usage: test_array test1|test2|test3|test4|test5|test6\n");
	exit(1);
    }

    test = argv[1];
    printf("Running %s\n", test);
    if (strcmp(test, "test1")==0) {
	test1();
    }
    else if (strcmp(test, "test2")==0) {
	test2();
    }
    else if (strcmp(test, "test3")==0) {
	test3();
    }
    else if (strcmp(test, "test4")==0) {
	test4();
    }
    else if (strcmp(test, "test5")==0) {
	test5();
    }
    else if (strcmp(test, "test6")==0) {
	test6();
    }
    else if (strcmp(test, "test7")==0) {
	test7();
    }
    else if (strcmp(test, "test8")==0) {
	test8();
    }
    else {
	printf("Test not found!\n");
	exit(1);
    }
}

