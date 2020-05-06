#include <stdlib.h>

/*
 *  NOTE NOTE NOTE NOTE NOTE
 *  You are not allowed to add any other libraries or library includes in addition
 *   to <stdlib.h> (if you believe you need it).
 */

/*	int minDiff(int A[], int B[], int lenA, int lenB)
 *
 *  Arguments:
 *		int A[] -- an array of integers
 *		int B[] -- an array of integers
 *		int lenA -- length of "A"
 *		int lenB -- length of "B"
 *
 *  Returns:
 *		int -- the smallest difference between 2 arbitrary integers in the array.
 *
 *  Description:
 *		The function determines and returns the minimum difference between two elements
 *		 in the given arrays, “A” and “B”.  The value of the minimum difference if found
 *		 by finding an element in “A”, and another in “B”, so that the magnitude
 *		 (absolute value) of the difference between them is as small as possible.
 *
 *	Example:
 *		minDiff({3, 6, 7, 4}, {2, 8, 9, 3}, 4, 4);  // returns 0 (3 - 3)
 *		minDiff({3}, {9}, 1, 1);  // returns 6 (|9-3|)
 *
 *	Hint:
 *		First set the 'min' value to the difference of the 0th elements in each array.
 *		 Then minimum difference is calculated by iterating through array "A".  For each
 *		 iteration, 'i', also iterate through array "B", iteration 'j', checking if
 *		 |"A[i]" - "B[j]"| is less than the current min.  If it is, the update the 'min'.
 *		 After the iterations are finished, return the 'min'.
 */

int absdiff(int a, int b);	//Declare absolute value function

int minDiff(int A[], int B[], int lenA, int lenB)
{
	int min = absdiff(A[0],B[0]);	//initialize as the difference of the 0th elements
	int i,j;	//For loop initializers
	for (i = 0; i < lenA; ++i){	//iterating thru array A
		for (j = 0; j < lenB; ++j){	//iterating thru array B
			if ( absdiff(A[i],B[j]) < min){
				min = absdiff(A[i],B[j]);	
			}	//end of if
		}	//end of for j 
	}	//end of for i 
	return min;
}

int absdiff(int a, int b){	//Define absolute value function
	int abs = a - b;
	if (abs < 0){
		return -abs;	
	}
	return abs;
}
