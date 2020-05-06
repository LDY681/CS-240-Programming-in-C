#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minDiff(int A[], int B[], int lenA, int lenB);

void printArray(int arr[], unsigned n)
{
	int i;
	printf("{");

	for (i = 0; i < n; i++) {
		printf("%d%s", arr[i], (i == n - 1) ? "}\n" : ", ");
	}
}

void test1()
{
	int A[] = {1, 2, 3, 4};
	int B[] = {0, 5, 3, 12};
	int lenA = sizeof(A) / sizeof(A[0]);
	int lenB = sizeof(B) / sizeof(B[0]);
	printArray(A, lenA);
	printArray(B, lenB);
	printf("Calculating minimum difference...\n");
	printf("The minimum difference = %d.\n", minDiff(A, B, lenA, lenB));
}

void test2()
{
	int A[] = {-1, -2, -3, -4};
	int B[] = {1, 2, 3, 4};
	int lenA = sizeof(A) / sizeof(A[0]);
	int lenB = sizeof(B) / sizeof(B[0]);
	printArray(A, lenA);
	printArray(B, lenB);
	printf("Calculating minimum difference...\n");
	printf("The minimum difference = %d.\n", minDiff(A, B, lenA, lenB));
}

void test3()
{
	int A[] = {100, 200, 300, 400};
	int B[] = {800, 900};
	int lenA = sizeof(A) / sizeof(A[0]);
	int lenB = sizeof(B) / sizeof(B[0]);
	printArray(A, lenA);
	printArray(B, lenB);
	printf("Calculating minimum difference...\n");
	printf("The minimum difference = %d.\n", minDiff(A, B, lenA, lenB));
}

void test4()
{
	int A[] = {0};
	int B[] = {~(1 << 31)};
	int lenA = sizeof(A) / sizeof(A[0]);
	int lenB = sizeof(B) / sizeof(B[0]);
	printArray(A, lenA);
	printArray(B, lenB);
	printf("Calculating minimum difference...\n");
	printf("The minimum difference = %d.\n", minDiff(A, B, lenA, lenB));
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