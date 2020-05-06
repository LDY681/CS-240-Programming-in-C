#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "review.h"

// Problem (1/4)
/******************************************************************************
 * : Return a pointer to the first occurrence of the character 'c' in the 
 * string 's'. Return NULL if the character is not found.
 * 
 * Parameters: s -- string
 *             c -- search for this character in the string 's'
 *
 * Return: pointer to the first occurene of the character c in the string s
 *
 * Return Type: char pointer
 *****************************************************************************/
char *strchr(const char *s, int c) 
{
	//TODO: s is a char pointer, s++ is the next char in the pointer
	//*s is the value of which the pointer points to 
	char *scopy = strdup(s);
	char find = (char) c;
	
	//int to char, (char) c
	
	//char to int, '0' -> 0
	//int ic = c - '0'
	
	//atoi string to int
	
	//char buffer [50]
	//sprintf(buffer, "%d", a) automatically add \0

	while (*scopy != '\0'){	//char string end with \0
		if (*scopy == find){
			return scopy;
		}
		scopy++;
	}

	//to return a pointer of a certain location, ++ to increment everytime, simply *(s+i) didnt work
	
}

// Problem (2/4)
/******************************************************************************
 * : Return the maximum element in the array
 * 
 * Parameters: array -- an integer array
 *             n -- number of elements in the array
 *
 * Return: the maximum element in the array
 *
 * Return Type: integer
 *****************************************************************************/
int max_array( int * array, int n )
{
	int max = *array;
	int count = 0;
	while ( count < n){
		if (*array > max){
			max = *array;
		}
		array++;
		count++;
	}
	return max;
}

// Problem (3/4)
/******************************************************************************
 * : Return the 'ith' bit in 'bitmap' (either 0 or 1)
 * 
 * Parameters: bitmap -- unsigned integer
 *             ith -- index of the bit to be returned
 *
 * Return: the largest element in the array 
 *
 * Return Type: integer
 *****************************************************************************/
int get_bit_at( unsigned int bitmap, int ith )
{	
	unsigned int bitcopy = bitmap;
	bitcopy = bitcopy >> ith;
	//bitwise operation is >> and << not ++
	//the leftover you & them with 1 (same as 0000000001) so the last bit you want is leftover 
	//TODO: know how to deal with neglect?
	int truth = bitcopy & 1;
	return truth;
}

// Problem (4/4)
/******************************************************************************
 * : Read from the file and store the entries in to a single linked list.
 * Return the list. Use the function llist_add( List * list, int value ) to
 * add entries to the list. 
 *
 * The file format will be:
 * value\n
 * value\n
 * value\n
 * ...
 *
 * Parameters: filename -- the name of the file you will be reading from
 *
 * Return: a singled linked list which contains the values read from the file
 *
 * Return Type: pointer to a single linked list
 *****************************************************************************/
List * llist_read( char * filename ) 
{
	List *list = (List*) malloc (sizeof(List));
	llist_init(list);
	FILE *file = fopen(filename,"r");
	//TODO: practice more on fgets
	char line [256];	
	while ( fgets(line, 256, file) != NULL){	
		//TODO: for fgets, s should be s [] not *s
		//return s on success, return NULL on error
		int value = atoi(line);
		llist_add(list, value);
	}
	return list;
	
}
