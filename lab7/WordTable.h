
#include "LinkedList.h"

struct WordInfo {
	char * word;
	LinkedList positions;
};

typedef struct WordInfo WordInfo;

struct WordTable {
	// Number of words in the array
	int nWords;

	// Maximum number of words in array before resiing
	int maxWords;
	WordInfo * wordArray;
};

typedef struct WordTable WordTable;

// Initializes a word table
void wtable_init(WordTable * wtable);

// Print contents of the table.
void wtable_print(WordTable * wtable, FILE * fd);

// Add word to the tableand position. Position is added to the corresponding linked list.
void wtable_add(WordTable * wtable, char * word, int position);

// Read a file and obtain words and positions of the words and save them in table.
// 
int wtable_createFromFile(WordTable * wtable, char * fileName, int verbose);

// Get pointer to list of positions where the word occurs
LinkedList * wtable_getPositions(WordTable * wtable, char * word);

// Sort table in alphabetical order.
void wtable_sort(WordTable * wtable);

// Print all segments of text in fileName that contain word.
// from pos-100 to pos+100. Use fseek to position file pointer.
// Type "man fseek" for more info. 
int wtable_textSegments(WordTable * wtable, char * word, char * fileName);

