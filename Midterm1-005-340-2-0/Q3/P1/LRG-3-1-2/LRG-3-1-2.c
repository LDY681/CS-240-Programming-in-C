#include <stdlib.h>

/*
 *  NOTE NOTE NOTE NOTE NOTE
 *  You are not allowed to add any other libraries or library includes in addition
 *   to <stdlib.h> (if you believe you need it).
 */

/*  void censorWord(char *str, char * badword)
 *
 *  Arguments:
 *		char * str -- a pointer to a string
 *      char * badword -- a word to replace in string
 *
 *  Description:
 *		The function is given a string of input and replaces all occurrences of
 *		 the word “badword” in “str” with X's. The word must have whitespace on
 *		 both sides (space, tab, newline or carriage return), unless it is at
 *		 the beginning/end of the string "str", and must match case. Word will not
 *		 have any whitespace characters in it.
 *
 *  Example:
 *		char *str = “The penguin is in the theater”
 *		censorWord(str, “the”);  // str points to “The penguin is in XXX theater”
 */

//func declaration
int len(char *a);
int match(char *str, char *badword, int i, int lenbad);

void censorWord(char *str, char *badword)
{
	int lenstr = len(str);
	int lenbad = len(badword);
	
	int i;
	for (i = 0; i < lenstr; ++i){
		if (str[i] == badword[0])	//find the first char of badword
			//diagnose if all chars of a badword matchs
			if ( match(str, badword, i, lenbad) == 1){
				int j;
				for (j = 0; j < lenbad; ++j){
					str[i] = 'X';
					++i;				
				}		
			}
	}

}

//func definition
int len(char *a){
	int len = 0;
	while ( a[len] != '\0'){
		++len;
	}
	return len;
}

int match(char *str, char *badword, int i, int lenbad){
	int j;
	for (j = 0; j < lenbad; ++j){
		if (str[i] != badword[j]){	
			return 0;	//return 0 if didnt match
		}
		++i;
		if (i == len(str)){
			return 0;		
		}
	}
	/*if (i != 0 && str[i-1]!= ' ' && str[i+lenbad] != ' '){
		return 0;
	}*/
	
	return 1;	//return 1 if matchs
}
