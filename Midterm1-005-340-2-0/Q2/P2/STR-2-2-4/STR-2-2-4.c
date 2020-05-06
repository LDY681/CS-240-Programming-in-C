#include <stdlib.h>

/*
 *  NOTE NOTE NOTE NOTE NOTE
 *  You are not allowed to add any other libraries or library includes in addition
 *   to <stdlib.h> (if you believe you need it).
 */

/*	void blankX(char *s, const char toRemove)
 *
 *  Arguments:
 *		char *s -- a pointer to a string
 *      const char toRemove -- a character to remove
 *
 *  Description:
 *		The function replaces every occurrence of the character “toRemove” in
 *		 the input string with a capital ‘X’.  The function preserves white
 *		 spaces and letter cases.
 *
 *	Example:
 *		blankX("Hello World", 'l');  // is now "HeXXo WorXd"
 */

void blankX(char *s, const char toRemove)
{
	int len = 0;	//start point of char array
	while(s[len] != '\0'){
		if (s[len] == toRemove){
		s[len] = 'X';		
		}
	++len;
	}
}
