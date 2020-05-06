#include <stdlib.h>
#include <math.h>

/*
 *  NOTE NOTE NOTE NOTE NOTE
 *  You are not allowed to add any other libraries or library includes in addition
 *   to <stdlib.h> other than <math.h> (if you believe you need it).
 */

/*  long int factorial(long int num)
 *
 *  Arguments:
 *		long int num -- an long integer
 *
 *  Returns:
 *		long int -- the factorial of "num" or (-1) if input is invalid
 *
 *  Description:
 *		The function determines and returns the factorial of the given integer,
 *		 "num" (i.e, num!).  The input, "num", should be greater than 0 and less
 *		 than 20, or the function should return (-1).
 *
 *	Note:
 *		 0! is 1, 1! is 1
 *		 Factorial of N is N * Factorial(N - 1)
 *
 *	Example:
 *		3! == 3 * 2 * 1 = 6
 *		5! == 5 * 4 * 3 * 2 * 1 = 120
 *
 *	Error:
 *		The function returns (-1) if "num" is < 0 or if "num" is > 20
 */

long int factorial(long int num)
{
	//Error case
	if (num < 0 || num > 20){
		return -1;
	}

	//Factorial function
	
	//0 and 1 case
	if (num == 0 || num == 1){
		return 1;
	}
	//General case
	long int i, fac;
	fac = 1;	//initialize fac sum;
	for (i = num; i > 1; --i){
		fac = fac * i;
	}
	return fac;
}
