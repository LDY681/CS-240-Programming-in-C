#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function Declarations
// Return minimum element of array
double minArray(int n, double * array);
// Print array
void printArray(int n, double * array);
// Reverse string
char * reverse_str( char * str );
// Is permutation
int is_permutation( char * str1, char * str2 );

double a[] = {4, 7, 2, 6, 1, 8, 9, 2, 11, -1, 3, 12};
int n = sizeof(a)/sizeof(double);

void test1() {
    printf("Printing Array A:\n");
    printArray(n, a);
    double b[] = {32, 124, 234, 3452, 9, 63.34};
    n = sizeof(b)/sizeof(double);
    printf("Printing Array B:\n");
    printArray(n, b);
}

void test2() {
  double s = minArray(n, a);
  printf("minArray=%lf\n", s);
}

void test3() {
    char * str = strdup("care");
    printf("Original String: %s\n", str);
    str = reverse_str( str ); 
    printf("Reversed String: %s\n", str);
}

void test4() {
    char * str = strdup("heavy");
    printf("Original String: %s\n", str);
    reverse_str( str ); 
    printf("Reversed String: %s\n", str);
}

void test5() {
    char * str = strdup("ROTAVATOR");
    printf("Original String: %s\n", str);
    str = reverse_str( str ); 
    printf("Reversed String: %s\n", str);
}

void test6() {
    char * str1 = "coral";
    char * str2 = "laroc";
    printf("STR1 = %s\n", str1);
    printf("STR2 = %s\n", str2);
    int val = is_permutation( str1, str2 );
    if ( val ) {
	printf("Is a permutation\n");
    }
    else {
	printf("Not a permutation\n");
    }
}

void test7() {
    char * str1 = "hello";
    char * str2 = "hole";
    printf("STR1 = %s\n", str1);
    printf("STR2 = %s\n", str2);
    int val = is_permutation( str1, str2 );
    if ( val ) {
	printf("Is a permutation\n");
    }
    else {
	printf("Not a permutation\n");
    }
}

void test8() {
    char * str1 = "purude";
    char * str2 = "edurpu";
    printf("STR1 = %s\n", str1);
    printf("STR2 = %s\n", str2);
    int val = is_permutation( str1, str2 );
    if ( val ) {
	printf("Is a permutation\n");
    }
    else {
	printf("Not a permutation\n");
    }

    printf("\n");

    str1 = "abd";
    str2 = "cbb";
    printf("STR1 = %s\n", str1);
    printf("STR2 = %s\n", str2);
    val = is_permutation( str1, str2 );
    if ( val ) {
	printf("Is a permutation\n");
    }
    else {
	printf("Not a permutation\n");
    }
}

int main(int argc, char ** argv) {

  char * test;
  
  if (argc <2) {
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
  
  return 0;
}

