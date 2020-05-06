#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int factorial(long int num);

long int num, res;

void test1()
{
	num = 3;
	printf("Factorial of %ld (%ld!) ", num, num);

	if ((res = factorial(num)) == -1) {
		printf("cannot be determined.\n");
	} else {
		printf("= %ld\n", res);
	}
}

void test2()
{
	num = 10;
	printf("Factorial of %ld (%ld!) ", num, num);

	if ((res = factorial(num)) == -1) {
		printf("cannot be determined.\n");
	} else {
		printf("= %ld\n", res);
	}
}

void test3()
{
	num = -5;
	printf("Factorial of %ld (%ld!) ", num, num);

	if ((res = factorial(num)) == -1) {
		printf("cannot be determined.\n");
	} else {
		printf("= %ld\n", res);
	}
}

void test4()
{
	num = 25;
	printf("Factorial of %ld (%ld!) ", num, num);

	if ((res = factorial(num)) == -1) {
		printf("cannot be determined.\n");
	} else {
		printf("= %ld\n", res);
	}
}

int main(int argc, char **argv)
{
	char *test;

	if (argc < 2) {
		printf("Usage: mytest <test#>\n");
		exit(1);
	}

	test = argv[1];
	printf("Running %s\n", test);

	if (strcmp(test, "test1") == 0) {
		test1();
	} else if (strcmp(test, "test2") == 0) {
		test2();
	} else if (strcmp(test, "test3") == 0) {
		test3();
	} else if (strcmp(test, "test4") == 0) {
		test4();
	} else {
		printf("Test not found!\n");
		exit(1);
	}

	return 0;
}