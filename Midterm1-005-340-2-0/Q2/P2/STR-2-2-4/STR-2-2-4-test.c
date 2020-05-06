#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void blankX(char *s, const char toRemove);

char *s, x;

void test1()
{
	s = strdup("Please Remove all my e's");
	x = 'e';

	printf("Removing all '%c's from \"%s\"...\n", x, s);
	blankX(s, x);
	printf("Result = \"%s\".\n", s);
	free(s), s = NULL;
}

void test2()
{
	s = strdup("I don't want any a's");
	x = 'a';

	printf("Removing all '%c's from \"%s\"...\n", x, s);
	blankX(s, x);
	printf("Result = \"%s\".\n", s);
	free(s), s = NULL;
}

void test3()
{
	s = strdup("\t\t tabs a\tre the\t\t\tworst\t\t");
	x = '\t';

	printf("Removing all '%c's from \"%s\"...\n", x, s);
	blankX(s, x);
	printf("Result = \"%s\".\n", s);
	free(s), s = NULL;
}

void test4()
{
	s = strdup("aaxxbbxxccxxddxxeexx");
	x = 'x';

	printf("Removing all '%c's from \"%s\"...\n", x, s);
	blankX(s, x);
	printf("Result = \"%s\".\n", s);
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