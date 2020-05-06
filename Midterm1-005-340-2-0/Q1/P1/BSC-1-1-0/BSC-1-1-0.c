#include <stdlib.h>
#include <math.h>

/*
 *  NOTE NOTE NOTE NOTE NOTE
 *  You are not allowed to add any other libraries or library includes in addition
 *   to <stdlib.h> other than <math.h> (if you believe you need it).
 */

/*  double sumArray(double array[], unsigned int n)
 *
 *  Arguments:
 *		double array[] -- an array of doubles
 *		unsigned int n -- the number of elements in "array"
 *
 *  Returns:
 *      double -- the sum of the elements in "array"
 *
 *  Description:
 *		The function determines and returns the sum of the elements in the given
 *		 array of doubles, "array".
 */

double sumArray(double array[], unsigned int n)
{
	// TODO
	
	int i;	//for loop initializer
	double sum = 0;	//initialize sum

	for (i = 0; i < n; ++i){
		sum = sum + array[i];	
	}
	return sum;
}
