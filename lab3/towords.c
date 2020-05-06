
#include <stdio.h>
#include <stdlib.h>

#include "nextword.h"

int main(int argc, char ** argv) {
	printf("Program that separates text to words.\n");

	if (argc < 2) {
	  printf("Usage: towords filename\n");
	  exit(1);
	}

	// Get file from first argument.
	char * fileName = argv[1];
	FILE * fd = fopen(fileName, "r");
	if (fd == NULL) {
	  printf("Could not open file %s\n", fileName);
	  exit(1);
	}

	char * w;
	int wordCount = 0;
	while ( (w = nextword(fd)) != NULL) {
	  printf("%d: %s\n", wordCount, w);
	  wordCount++;
	}
	printf("words total = %d\n", wordCount);

	fclose(fd);

	exit(0);
}

