
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "WordTable.h"

// Initializes a word table
void wtable_init(WordTable * wtable)
{
	// Allocate and initialize space for the table
	wtable->nWords = 0;
	wtable->maxWords = 10;
	wtable->wordArray = (WordInfo *) malloc(wtable->maxWords * sizeof(WordInfo));
	for (int i = 0; i < wtable->maxWords; i++) {
		llist_init(&wtable->wordArray[i].positions);
	}
}

// Add word to the tableand position. Position is added to the corresponding linked list.
void wtable_add(WordTable * wtable, char * word, int position)
{
	// Find first word if it exists
	for (int i = 0; i < wtable->nWords; i++) {
		if ( strcmp(wtable->wordArray[i].word, word)== 0 ) {
			// Found word. Add position in the list of positions
			llist_insert_last(&wtable->wordArray[i].positions, position);
			return;
		}
	}

	// Word not found.

	// Make sure that the array has space.
	// Expand the wordArray here.
        if (wtable->nWords == wtable->maxWords){
		wtable->maxWords = wtable->maxWords*2;
		wtable->wordArray = realloc(wtable->wordArray, wtable->maxWords*sizeof(WordInfo));

	}
       
	// Add new word and position
	wtable->wordArray[wtable->nWords].word = strdup(word);
	llist_insert_last(&wtable->wordArray[wtable->nWords].positions, position);
	wtable->nWords++;
}

// Print contents of the table.
void wtable_print(WordTable * wtable, FILE * fd)
{
	fprintf(fd, "------- WORD TABLE -------\n");

	// Print words
	for (int i = 0; i < wtable->nWords; i++) {
		fprintf(fd, "%d: %s: ", i, wtable->wordArray[i].word);
		llist_print( &wtable->wordArray[i].positions);
	}
}

// Get positions where the word occurs
LinkedList * wtable_getPositions(WordTable * wtable, char * word)
{
	// Write your code here
	int i = 0;
	while (i < wtable->nWords){
		if (strcmp(word, wtable->wordArray[i].word ) == 0){
			return  &wtable->wordArray[i].positions;
		}
		++i;
	}
	return NULL;
}

//
// Separates the string into words
//

#define MAXWORD 200
char word[MAXWORD];
int wordLength;
int wordCount;
int charCount;
int wordPos;

// It returns the next word from stdin.
// If there are no more more words it returns NULL.
// A word is a sequence of alphabetical characters.
static char * nextword(FILE * fd) {

	// Write your code here
	char *c = (char*)malloc(100*sizeof(char));
	char *str = c;
	*c = fgetc(fd);
	
	//if no more word
	if (*c == EOF){
		return NULL;
	}

	//return next word
	while(1){
		//if no more letter, return all
		if ( !((*c >= 'A' && *c <= 'Z') || (*c >= 'a' && *c <= 'z')) ){
			*c = '\0';	//terminate at non-letter
			return str;			
		}
		c++;
		*c = fgetc(fd);

		if (*c == EOF){
			return NULL;
		}
	}

	
        return NULL;
}

// Conver string to lower case
void toLower(char *s) {
	if (s == NULL){
		return;
	}
	while (*s != '\0'){
		if (*s >= 'A' && *s <= 'Z'){
			*s = *s - 'A' + 'a';
		}
		s++;
	}
}


// Read a file and obtain words and positions of the words and save them in table.
int wtable_createFromFile(WordTable * wtable, char * fileName, int verbose)
{

	//TODO: use nextword
	// Open file stream and start at beginning
	FILE *fp = fopen(fileName, "r");
	if (fp == NULL){
		return 0;
	}
	//fseek(fp, 0, SEEK_SET);


	int count = 0;
	int pos = ftell(fp);
	char *str = malloc(100*sizeof(char));
	str = nextword(fp);

	//Firs word case
	while ( !((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')) ){
			pos = ftell(fp);
			str = nextword(fp);
	}
	toLower(str);
	
	while (str != NULL){
		wtable_add(wtable, str, pos);

		if (verbose == 1){
			printf("%d: word=%s, pos=%d\n", count, str, pos);
		}
	

		//Update
		count++;
		pos = ftell(fp);
		str = nextword(fp);

		toLower(str);	//toLower returns void

		//Skip \0 word, generated from nextword function
		while (str != NULL && !((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')) && *str == '\0'){
			pos = ftell(fp);
			str = nextword(fp);	
		}
		toLower(str);
	}
	
	//dont forget to fclose at end
	fclose(fp);
	return 0;
}

// Sort table in alphabetical order.
void wtable_sort(WordTable * wtable){
  	int i, j;
	for (i = 0; i < wtable->nWords-1; i++){      
    		for (j = 0; j < wtable->nWords-i-1; j++) {
          		if (strcmp(wtable->wordArray[j].word, wtable->wordArray[j+1].word) >= 1){
				//SWAP
				struct WordInfo swap;
				swap.word = wtable->wordArray[j+1].word;
				swap.positions = wtable->wordArray[j+1].positions;

				wtable->wordArray[j+1].word = wtable->wordArray[j].word;
				wtable->wordArray[j+1].positions = wtable->wordArray[j].positions;

				wtable->wordArray[j].word = swap.word;
				wtable->wordArray[j].positions = swap.positions;
			}      
       		}
   	}

}

// Print all segments of text in fileName that contain word.
// at most 200 character. Use fseek to position file pointer.
// Type "man fseek" for more info. 
int wtable_textSegments(WordTable * wtable, char * word, char * fileName)
{
	
	FILE *fp = fopen(fileName, "r");

	printf("===== Segments for word \"%s\" in book \"%s\" =====\n", word , fileName);

	LinkedList *occur = wtable_getPositions(wtable,word);
	ListNode *e = occur->head;
	
	while(e != NULL){
		printf("---------- pos=%d-----\n", e->value);
		printf("......");
		fseek(fp, e->value, SEEK_SET);
		int i;
		for (i = 0; i < 200; ++i){
			char c = fgetc(fp);
			printf("%c",c);
		}
		printf("......\n");
		e=e->next;
	}
	
}

