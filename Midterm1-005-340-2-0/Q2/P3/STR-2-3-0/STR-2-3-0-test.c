#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *delChars(const char *s1, const char *s2);

char *s1, *s2;

void test1()
{
	s1 = strdup("Hello World");
	s2 = strdup("Said George");
	printf("\"%s\" without \"%s\" is \"%s\"\n", s1, s2, delChars(s1, s2));
	free(s1), s1 = NULL;
	free(s2), s2 = NULL;
}

void test2()
{
	s1 = strdup("abcdefghijklmnopqrstuvwxyz");
	s2 = strdup("the quick brown fox jumped over the lazy dog");
	printf("\"%s\" without \"%s\" is \"%s\"\n", s1, s2, delChars(s1, s2));
	free(s1), s1 = NULL;
	free(s2), s2 = NULL;
}

void test3()
{
	s1 = strdup("\t\t!!##%%&&((\t\t");
	s2 = strdup("\t%%");
	printf("\"%s\" without \"%s\" is \"%s\"\n", s1, s2, delChars(s1, s2));
	free(s1), s1 = NULL;
	free(s2), s2 = NULL;
}

void test4()
{
	s1 = strdup("G  O   O  G  L   E");
	s2 = strdup(" ");
	printf("\"%s\" without \"%s\" is \"%s\"\n", s1, s2, delChars(s1, s2));
	free(s1), s1 = NULL;
	free(s2), s2 = NULL;
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