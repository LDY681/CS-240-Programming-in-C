
#include <stdlib.h>
#include <stdio.h>

int
main(int argc, char ** argv) {
	int c;

	printf("Program that prints the ascii values of the characters in a file\n");

	if (argc < 2) {
	  printf("Usage: toascii filename\n");
	  exit(1);
	}

	// Get file from first argument.
	char * fileName = argv[1];
	FILE * fd = fopen(fileName, "r");
	if (fd == NULL) {
	  printf("Could not open file %s\n", fileName);
	  exit(1);
	}

	// Iterate over all characters in file and pront them
	while ((c=fgetc(fd))!=-1) {
		printf("<%c,%d>\n",c,c);
	}
	
	fclose(fd);
}

