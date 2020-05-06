
#include <stdio.h>

#include "array.h"

// Return sum of the array
double sumArray(int n, double * array) {
  double sum = 0;
  
  double * p = array;
  double * pend = p+n;

  while (p < pend) {
    sum += *p;
    p++;
  }

  return sum;
}

// Return maximum element of array
double maxArray(int n, double * array) {
	int len = 0;
	double* arraycopy = array;
	while (*arraycopy){
		len++;
		arraycopy++;
	}
	
	double* arraycopy2 = array;
	int start = 0;
	double maxe = 0;
	while (start < len){
		if (*arraycopy2 > maxe){
			maxe = *arraycopy2;
		}
		arraycopy2++;
		start++;
	}
  return maxe;
}

// Return minimum element of array
double minArray(int n, double * array) {
	int len = 0;
	double* arraycopy = array;
	while (*arraycopy){
		len++;
		arraycopy++;
	}
	
	double* arraycopy2 = array;
	int start = 0;
	double mine = *arraycopy2;
	while (start < len){
		if (*arraycopy2 < mine){
			mine = *arraycopy2;
		}
		arraycopy2++;
		start++;
	}
  return mine;
}

// Find the position in the array of the first element x 
// such that min<=x<=max or -1 if no element was found
int findArray(int n, double * array, double min, double max) {
	int pos = 0;
	double* p = array;
	while (*p){
		if ( min < *p && *p < max ){
			return pos;
		}
		pos++;
		p++;
	}
	return -1;
}

// Sort array without using [] operator. Use pointers 
// Hint: Use a pointer to the current and another to the next element
int sortArray(int n, double * array) {
	int i, j;
	double swap;
	for (i = 0 ; i < ( n - 1 ); i++){
   		for (j = 0 ; j < n - i - 1; j++){
      			if ( *(array+j) > *(array+j+1) ){
        			swap = *(array+j);
        			*(array+j) = *(array+j+1);
        			*(array+j+1) = swap;
      			}
    		}
  	}
	return 0;
}

// Print array
void printArray(int n, double * array) {
	int i;
	for (i = 0; i< n; ++i){
		printf("%d:%f\n", i, *array);
		array++;
	}
}

