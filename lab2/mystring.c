
#include <stdlib.h>
#include "mystring.h"

// Type "man string" to see what every function expects.

int mystrlen(char * s) {
	int len = 0; // string length
	int key = 0; // = 1 when need to break
	while (key == 0){
		if (s[len] != '\0'){
			++len;
		}else key = 1;
	}

	return len;
}

char * mystrcpy(char * dest, char * src) {
	int len = 0; // src length
	int i = 0; //initialize loop
	len = mystrlen(src);
	/*if(len == 0){
		return src;
	}*/
	for (i = 0; i < len; i++){
		dest[i] = src [i];
	}	//For loop
	dest[i] = '\0';
	//free(src);
	return dest;
}

char * mystrcat(char * dest, char * src) {
	int lsrc = mystrlen(src);	//length of src
	int ldest = mystrlen(dest);	//length of dest
	int total = lsrc + ldest;	//total length
	
	int i;
	for(i = ldest; i < total; i++) {

		dest[i] = src[i - ldest];
		}
	dest[i] = '\0';

	return dest;
}

int mystrcmp(char * s1, char * s2) {
	int len1 = mystrlen( s1 );
	int len2 = mystrlen( s2 );
	
	if( len1 > len2){
		return 1;
	}else if( len1 < len2){
		return -1;
	}else{
	}

	int i = 0; //Initial number
	
	while ( s1[i] != '\0' && s2[i] != '\0' ){
		if ( s1[i] > s2[i]){
			return 1;
		}else if( s1[i] < s2[i] ){
			return -1;
		}else{}
		i++;	
	}

	return 0;
}

// hay is the string
// needle is where to start
char * mystrstr(char * hay, char * needle) {
int lneed = mystrlen( needle );	//The length of needle
	int lhay = mystrlen( hay );	//The length of hay
	int i = 0;	//the number to check all the way till the end of hay
	int j = 0;	//the number to check all the way till the end of needle
	int sp = 0;     //start point

	//To judge if needle matches anywhere of the hay
	for ( i = 0; i < lhay; i++){
		int k = i;
		while( j < lneed ){
			if( hay[k] != needle[j]){
				j = 0;
				break;
			}	//end of if hay != need

			if( hay[k] == needle[j]){
				j++;
				k++;
			}	// end of if hay = need

			//If any of the needle doesnt match the hay
				
		}	//end of while j < lneed
		
		//if all needle matches the hay
		if ( j == lneed){
			//set startpoint
			sp = i; 
			char *whatsleft = (char*) malloc( (lhay - sp + 1) * sizeof(char));
			//To copy everthing after startpoint
			for ( sp = i; sp < lhay; sp++){
				whatsleft[sp - i] = hay[sp];				
			}
			return whatsleft;
		}

	
	}	//end of for loop
	
	return NULL;
}

char * mystrdup(char * s) {
	int len = mystrlen(s);	//length of input string

	//malloc a location for storage the duplicate
	char *dup = (char*) malloc ( len * sizeof(char) );

	//copy s to dup
	mystrcpy(dup, s);

	return dup;
}

char * mymemcpy(char * dest, char * src, int n)
{
	/* copy at most n bytes from src to dest
	 * return a pointer to the start of dest
	 */
	int i;
	for (i = 0; i < n; i++){
		dest[i] = src[i];
	}
	return dest;
}

