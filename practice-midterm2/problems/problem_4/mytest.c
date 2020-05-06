#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toInteger(char * number, int base);
char * toBase(int number, int base);

// Test Functions
void test1() {
	// Test toInteger
	printf("convert the string \"FF\" in base 16 to an integer: %d (base 10)\n", toInteger("FF", 16));
	printf("convert the string \"16\" in base 8 to an integer: %d (base 10)\n", toInteger("16", 8));
	printf("convert the string \"1010\" in base 2 to an integer: %d (base 10)\n", toInteger("1010", 2));
}

void test2() {
	// Test toBase
	printf("convert an integer with value 42 to a string in base 8: %s\n", toBase(42, 8));
	printf("convert an integer with value 1869 to a string in base 10: %s\n", toBase(1869, 10));
	printf("convert an integer with value 123 to a string in base 16: %s\n", toBase(123, 16));
}

void test3() {
	// Test  both functions
	printf("convert the string \"77\" in base 8 to a string in base 2: %s\n", toBase(toInteger("77", 8), 2));
	printf("convert the string \"240\" in base 10 to a string in base 16: %s\n", toBase(toInteger("240", 10), 16));
	printf("convert the string \"182\" in base 16 to a string in base 10: %s\n", toBase(toInteger("182", 16), 10));
}

void usage() {
	puts("Usage: ./mytest test1 | test2 | test3");
}

int main(int argc, char ** argv) {
	if (argc != 2) {
		usage();
		exit(1);
	}

	if (!strcmp(argv[1], "test1")) {
		test1();
	} else if (!strcmp(argv[1], "test2")) {
		test2();
	} else if (!strcmp(argv[1], "test3")) {
		test3();
	} else {
		usage();
	}
}
