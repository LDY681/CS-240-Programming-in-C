#include <stdlib.h>

/*
 *  NOTE NOTE NOTE NOTE NOTE
 *  You are not allowed to add any other libraries or library includes in addition
 *   to <stdlib.h> (if you believe you need it).
 */

/*	int mystrlen(const char *s)
 *
 *  Arguments:
 *		const char *s -- a pointer to a string
 *
 *  Returns:
 *		int -- the length of "s"
 *
 *  Description:
 *		The function determines the number of bytes in the string to which “s”
 *		 points, not including the terminating null byte. The function returns
 *		 the length of “s”; the function has no failure mode and no error
 *		 return.
 *
 *	Example:
 *		mystrlen("Hello");  // returns 5
 */

int mystrlen(const char *s)
{
	int len = 0;	//initial len
	
	
	while( s[len] != '\0'){
		++len; 		
	}
	return len;
}
