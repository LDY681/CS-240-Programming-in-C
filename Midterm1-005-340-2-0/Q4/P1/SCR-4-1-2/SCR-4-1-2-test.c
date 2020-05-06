#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printTriangles();

int check(const char *fname);

const char *F_TEST = "SCR-4-1-2.c";
const char *FUNC = "printTriangles()";

void test1(const char *prog)
{
	if (!strcmp(prog, "./mytest") || !strcmp(prog, "mytest")) {

		FILE *fp;

		if ((fp = fopen(F_TEST, "r")) == NULL) {
			printf("The file does not exist.\n");

		} else {
			printf("The file exists.\n");
			fclose(fp);
		}

	} else if (!strcmp(prog, "./mytest.org") || !strcmp(prog, "mytest.org")) {
		printf("The file exists.\n");
	}
}

void test2(const char *prog)
{
	if (!strcmp(prog, "./mytest") || !strcmp(prog, "mytest")) {

		if (!check(F_TEST)) {
			printf("The file does not contain the function \"%s\".\n", FUNC);

		} else {
			printf("The file contains the function \"%s\".\n", FUNC);
		}

	} else if (!strcmp(prog, "./mytest.org") || !strcmp(prog, "mytest.org")) {
		printf("The file contains the function \"%s\".\n", FUNC);

	} else {
		printf("Invalid input to test2 -- %s.\n", prog ? prog : "null");
	}
}

void test3(const char *prog)
{
	printf("Reading in integers...\n");
	printf("Triangles:\n");
	printTriangles();
}

void test4(const char *prog)
{
	printf("Reading in integers...\n");
	printf("Triangles:\n");
	printTriangles();
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
		test1(*argv);
	} else if (strcmp(test, "test2") == 0) {
		test2(*argv);
	} else if (strcmp(test, "test3") == 0) {
		test3(*argv);
	} else if (strcmp(test, "test4") == 0) {
		test4(*argv);
	} else {
		printf("Test not found!\n");
		exit(1);
	}

	return 0;
}

int check(const char *fname)
{
	FILE *fp;

	if ((fp = fopen(fname, "r")) == NULL) {
		fprintf(stderr, "  Error: invalid file %s\n", fname);
		exit(EXIT_FAILURE);
	}

	size_t len;
	char *line = NULL;

	while ((int)(len = getline(&line, &len, fp)) > 0) {
		if (strstr(line, FUNC) != NULL) {
			return 1;
		}

		free(line);
		line = NULL;
	}

	return 0;
}
