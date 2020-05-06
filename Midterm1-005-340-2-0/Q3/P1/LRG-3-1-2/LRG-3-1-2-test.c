#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void censorWord(char *str, char *badword);

char *s, *x;

void test1()
{
	s = strdup("the quick brown fox jumped over the lazy dog");
	x = strdup("the");

	printf("Censoring \"%s\" from \"%s\"...\n", x, s);
	censorWord(s, x);
	printf("Result = \"%s\".\n", s);
	free(s), s = NULL;
	free(x), x = NULL;
}

void test2()
{
	s = strdup("THE quick brown fox jumped over the lazy dog");
	x = strdup("THE");

	printf("Censoring \"%s\" from \"%s\"...\n", x, s);
	censorWord(s, x);
	printf("Result = \"%s\".\n", s);
	free(s), s = NULL;
	free(x), x = NULL;
}

void test3()
{
	s = strdup("the thethethe");
	x = strdup("the");

	printf("Censoring \"%s\" from \"%s\"...\n", x, s);
	censorWord(s, x);
	printf("Result = \"%s\".\n", s);
	free(s), s = NULL;
	free(x), x = NULL;
}

void test4()
{
	s = strdup("This censors out the word censor");
	x = strdup("censor");

	printf("Censoring \"%s\" from \"%s\"...\n", x, s);
	censorWord(s, x);
	printf("Result = \"%s\".\n", s);
	free(s), s = NULL;
	free(x), x = NULL;
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
