#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function Declarations
extern void setBitAt( unsigned int * bitmap, int i, int bitValue);
extern int getBitAt( unsigned int bitmap, unsigned int i);
extern int countBits( unsigned int bitmap, unsigned int bitValue);
extern void printBits(unsigned int bitmap);

// Test Functions
void test1()
{
    unsigned int a = 9;

    unsigned int b = 3;

    printf("a:\n");
    printBits(a);

    printf("b:\n");
    printBits(b);

    printf("a&b:\n");
    printBits(a&b);

    printf("a|b:\n");
    printBits(a|b);

    printf("a^b:\n");
    printBits(a^b);

    printf("~a:\n");
    printBits(~a);
}

void test2()
{
    unsigned int a = 9;

    printf("a:\n");
    printBits(a);

    setBitAt(&a, 10, 1);

    printf("a after setBitAt(&a,10,1):\n");

    printBits(a);
    setBitAt(&a, 20, 1);

    printf("a after setBitAt(&a,20,1):\n");
    printBits(a);


    setBitAt(&a, 0, 0);
    printf("a after setBitAt(&a,0,0):\n");
    printBits(a);

    setBitAt(&a, 3, 0);
    printf("a after setBitAt(&a,3,0):\n");
    printBits(a);


}

void test3()
{
    unsigned int a = 0xFFFF1009;

    printf("a:\n");
    printBits(a);

    int v = getBitAt(a, 3);
    printf("getBitAt(3)=%d\n", v);


    v = getBitAt(a, 10);
    printf("getBitAt(10)=%d\n", v);


    v = getBitAt(a, 20);
    printf("getBitAt(20)=%d\n", v);

    v = getBitAt(a, 5);
    printf("getBitAt(5)=%d\n", v);
}

void test4()
{
    unsigned int a = 0x6F245FF2;
    unsigned int b = 0x7F67FF89;

    printf("a:\n");
    printBits(a);
    printf("countBits(a,1)=%d\n", countBits(a,1));
    printf("countBits(a,0)=%d\n", countBits(a,0));

    printf("b:\n");
    printBits(b);
    printf("countBits(b,1)=%d\n", countBits(b,1));
    printf("countBits(b,0)=%d\n", countBits(b,0));
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
  else {
    printf("Test not found!\n");
    exit(1);
  }
  
  return 0;
}

