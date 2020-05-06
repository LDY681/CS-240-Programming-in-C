
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char ** argv) {
	int c;
	int lines=0;

	//Check Arguments length
	if (argc < 2){
		printf("Program that counts lines.\n");
		printf("Usage: countlines filename\n");
		exit(1);
	}

	//Read input file
	char *filename = argv[1];
	FILE *fd = fopen(filename, "r");

	//If no file found, fd = NULL
	if (fd == NULL){
		printf("Program that counts lines.\n");
		printf("Could not open file %s\n", filename);
		exit(1);
	}

	//Now we count lines
	while ((c = fgetc(fd)) != EOF) {
		if (c == '\n') {
				++lines;
		}
	}

	printf("Program that counts lines.\n");
	printf("Total lines: %d\n", lines);
	return lines;
}
