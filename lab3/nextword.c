#include <stdio.h>
#include <stdlib.h>

//
// Separates the file into words
//

#define MAXWORD 200
char word[MAXWORD];
int wordLength;

// It returns the next word from fd.
// If there are no more more words it returns NULL. 
char * nextword(FILE * fd) {
/*
	int increment = 0;
	int ]	wordLength = 0;
	// While it is not EOF read char
	while ((c = fgetc(fd)) != EOF) {
		//If it is a non-space char
		if (c != ' ' && c != '\n'  && c != '\t' && c != '\r') {
			// store character in word.
			word[wordLength] = c;
			++wordLength;
		}else if( c == ' ' || c == '\n' || c == '\t' || c == '\r') {
			//space at the end of the word

			if (wordLength != 0){
				word[wordLength] = '\0';
				//To deal with situations that incremented
				if (increment == 1){
					//Check how many spaces are there
					int i;
					for( i = 0; i < wordLength - 1; i++){
						word[i] = word[i + 1];
					}
					word[wordLength - 1] = '\0';
				}
				return word;
			}else{  //If There are spaces before the word
			
				increment = 1;
				++wordLength;
			}
		}
	}
*/

	int c = 0;	
	word[c]=fgetc(fd);
	//while (word[c] != EOF){
		//Ignore all the spaces before the word
		while (word[c] == ' ' || word[c] == '\n' || word[c] == '\t' || word[c] == '\r'){
			word[c] = fgetc(fd);
		}
		while (word[c] != ' ' && word[c] != '\n' && word[c] != '\t' && word[c] != '\r' && word[c] != EOF){
			++c;
			word[c] = fgetc(fd);
		}
			word[c] = '\0';
		

	if (c != 0 ){
	return word;}

	return NULL;
}
