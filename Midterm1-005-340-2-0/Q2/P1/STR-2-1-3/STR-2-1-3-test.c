#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrlen(const char *s);

char *s;

void test1()
{
	s = strdup("Normal String");

	printf("The length of \"%s\" is %d.\n", s, mystrlen(s));
	free(s), s = NULL;
}

void test2()
{
	s = strdup("This is a long line of text");

	printf("The length of \"%s\" is %d.\n", s, mystrlen(s));
	free(s), s = NULL;
}

void test3()
{
	s = strdup("\t\t\\\"\\\"");

	printf("The length of \"%s\" is %d.\n", s, mystrlen(s));
	free(s), s = NULL;
}

void test4()
{
	s = strdup("");

	printf("The length of \"%s\" is %d.\n", s, mystrlen(s));
	free(s), s = NULL;
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