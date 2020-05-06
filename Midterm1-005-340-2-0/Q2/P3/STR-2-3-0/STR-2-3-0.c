#include <stdlib.h>

/*
 *  NOTE NOTE NOTE NOTE NOTE
 *  You are not allowed to add any other libraries or library includes in addition
 *   to <stdlib.h> (if you believe you need it).
 */

/*	char *delChars(const char *s1, const char *s2)
 *
 *  Arguments:
 *		const char *s1 -- a pointer to a string
 *      const char *s2 -- a pointer to a string
 *
 *  Function return:
 *      char * -- pointer a string that contains the characters in "s1 that are
 *		 not in "s2".
 *
 *  Description:
 *		The function creates a new string with the characters from “s1” that
 *		 ignores any character that  is in contained in “s2”.
 *
 *	Example:
 *		delChars("Hello World", "Said George");  // returns "HllWl"
 */

char *delChars(const char *s1, const char *s2)
{
	int newi = 0;
	
	//everytime when creating a new array, dont forget to malloc
	char *new = (char*)malloc(200 * sizeof(char));	//declare a new array to store()
	
	//get the total len of s1
	int len1 = 0;
	while(s1[len1] != '\0'){
		++len1;
	}	//after while loop, len1 store the length of s1

	//get the total len of s2
	int len2 = 0;
	while(s2[len2] != '\0'){
		++len2;
	}	//after while loop, len2 store the length of s2
	
	//For loop
	int i, j;
	int del = 0;	//del = 0 if dont need to del; del = 1 if need to del
	for (i = 0; i < len1; ++i){
		for (j = 0; j < len2; ++j){
			if (s1[i] == s2[j]){
				del = 1;
			}
		}	//end of j

		//after the for j loop, if del = 0
		//then dont need to del, we store it to new
		if (del == 0){
			new[newi] = s1[i];
			++newi;
		}		
		del = 0;	//reset del

	}	//end of for i 
	
	//check
	new[newi] = '\0';
	return new;
}
