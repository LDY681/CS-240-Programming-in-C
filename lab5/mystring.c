
#include <stdlib.h>
#include "mystring.h"

int mystrlen(char * s) {
	int i = 0;
	while(*s){
		s++;
		i++;
	}
	return i;
}

char * mystrcpy(char * dest, char * src) {
	char *s = src;
	char *d = dest;
	while (*s){
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
	return dest;
}

char * mystrcat(char * dest, char * src) {
	char *d, *s;
	d = dest;
	while(*d){
		d++;
	}
	s = src;

	while(*s){
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
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

	char *d = s1;
	char *s = s2;
	while (*d && *s){
		if (*d < *s){
			return -1;
		}else if (*d > *s){
			return 1;
		}else{
			d++;
			s++;
		}
	}
	return 0;
}

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
			if( *(hay+k) != *(needle+j)){
				j = 0;
				break;
			}	//end of if hay != need

			if( *(hay+k) ==  *(needle+j)){
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
				*(whatsleft+sp-i) = *(hay+sp);				
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

char * mymemcpy(char * dest, char * src, int n){
	int i;
	for (i = 0; i < n; i++){
		*(dest+i) = *(src+i);
	}
	return dest;
	
}

