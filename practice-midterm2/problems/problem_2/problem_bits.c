#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Problem (1/4)
/******************************************************************************
 * TODO: Print the bits in bitmap as 0s and 1s
 * 
 * Parameters: bitmap -- print the binary representation of this number
 *
 * Return: void 
 *
 * Return Type: void
 *****************************************************************************/
void printBits(unsigned int bitmap)
{
	int i = 31;
	int k;
	while (i >= 0){
		k = bitmap >> i;
		if (k & 1){
			printf("1");
		}else{
			printf("0");
		}
		i--;	
	}

	/*
	int *store = (int*)malloc(32*sizeof(int));

	//Store bit presentation
	int i;
	for (i = 0; i< 32; i++){
		if (bitmap%2 == 0){	*(store+i) = 0;
		}else{	*(store+i) = 1;}
		bitmap = bitmap>> 1;
	}
	
	//Reverse Print
	for (i = 31; i >= 0; i--){
		printf("%d", *(store+i));
	}

	*/
	printf("\n");
	printf("10987654321098765432109876543210\n"); 
}


// Problem (2/4)
/******************************************************************************
 * TODO: Set the ith bit in *bitmap with the value in bitValue (0 or 1)
 * 
 * Parameters: bitmap -- unsigned integer
 *	       i -- index of the bit to be changed
 *             bitValue -- change the ith bit to this value
 *
 * Return: void 
 *
 * Return Type: void
 *****************************************************************************/
void setBitAt( unsigned int *bitmap, int i, int bitValue ) 
{
	int k = 1 << i;
	if (bitValue == 1){
		*bitmap |= 1 << i;	//ÓÃ| 0|1 = 1£» 1|1 = 1;
	}
	if (bitValue == 0){
		*bitmap &= ~(1 << i) ;
	}
	
	/*
	*bitmap = *bitmap >> i;
	*bitmap = bitValue;
	*bitmap = *bitmap << i;
	*/
}

// Problem (3/4)
/******************************************************************************
 * TODO: Return the bit value (0 or 1) at the ith bit of the bitmap
 * 
 * Parameters: bitmap -- unsigned integer
 *	       i -- index of the bit to be retrieved
 *
 * Return: the ith bit value 
 *
 * Return Type: integer
 *****************************************************************************/
int getBitAt( unsigned int bitmap, unsigned int i) {
    int k = bitmap >> i;
    if (k &1){
    	return 1;
    }else{
    	return 0;
    }
}

// Problem (4/4)
/******************************************************************************
 * TODO: Return the number of bits with the value 'bitValue'
 *	 If the bitValue is 0, return the number of 0s. If the bitValue is 1,
 *	 return the number of 1s.
 * 
 * Parameters: bitmap -- unsigned integer
 *	       bitValue -- count how many times this number, either 0 or 1,
 *	       appears in bitmap
 *
 * Return: count of 0s or 1s in bitmap 
 *
 * Return Type: integer
 *****************************************************************************/
int countBits( unsigned int bitmap, unsigned int bitValue) {
    int count = 0;
    int i = 31;
    while (i >= 0){
    	int k = bitmap >> i;
	if (bitValue == 1){
		if (k & 1){
			count++;
		}
	}else{
		if ( !(k&1) ){
			count++;
		}
	}
    	i--;
    }
    return count;
}

