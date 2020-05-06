#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double sumArray(double array[], unsigned int n);

void printArray(double arr[], unsigned n)
{
	int i;
	printf("{");

	for (i = 0; i < n; i++) {
		printf("%f%s", arr[i], (i == n - 1) ? "}\n" : ", ");
	}
}

void test1()
{
	double a[5] = {1, 2, 3, 4, 5};
	int lenA = sizeof(a) / sizeof(a[0]);
	printArray(a, lenA);
	printf("Summed Array: %f\n", sumArray(a, lenA));
}

void test2()
{
	double b[4] = {0.1, 0.2, 0.3, 0.4};
	int lenB = sizeof(b) / sizeof(b[0]);
	printArray(b, lenB);
	printf("Summed Array: %f\n", sumArray(b, lenB));
}

void test3()
{
	double c[2] = {-15.4, 16.0};
	int lenC = sizeof(c) / sizeof(c[0]);
	printArray(c, lenC);
	printf("Summed Array: %f\n", sumArray(c, lenC));
}

void test4()
{
	double d[3] = {2.1111, -2.1112};
	int lenD = sizeof(d) / sizeof(d[0]);
	printArray(d, lenD);
	printf("Summed Array: %f\n", sumArray(d, lenD));
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