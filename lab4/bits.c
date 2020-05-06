#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// It prints the bits in bitmap as 0s and 1s.
void printBits(unsigned int bitmap){
	/*int i;
	char* store = (char*) malloc (32 * sizeof(char));
	for (i = 0; i < 32; ++i){
		int j = bitmap >>i;
		store[i] = j%2 + '0';
		//printf("%d",j%2);
	}
	store[i] = '\0';
	
	char* reverse = (char*) malloc (32 * sizeof(char));	//reverse the order of store
	int j;
	for (j = 0 ; j < i; ++j){
		reverse[j] = store[i-j -1];
	}
	reverse[i] = '\0';
	*/

	
	int negative = 0; //0 is false
	if (bitmap > 2147483647){
		bitmap = ~bitmap;
		negative = 1;
	}

	//convert dec to binary
	int left = bitmap;	//left = number/baseto
	int remain = 0;	//Remainder
	char* store = (char*) malloc (32 * sizeof(char));
	int i = 0;
	while(left > 0){

		//store the remainder
		remain = left%2;
		store[i] = remain + '0';

		++i; 

		//do the division process
		left = left/2;			
	}
	store[i] = '\0';

	char* reverse = (char*) malloc (32 * sizeof(char));	//reverse the order of store
	int j;
	for (j = 0 ; j < i; ++j){
		reverse[j] = store[i-j -1];
	}
	reverse[i] = '\0';

	char* total = (char*) malloc (32* sizeof(char));
	char* addup = (char*) malloc ((32-i) *sizeof(char));
	int abc;
	for (abc = 0; abc < 32-i; ++abc){
		addup[abc] = '0';
	}
	strcat(total, addup);
	strcat(total, reverse);

	if (negative == 1){
		int neg;
		for (neg = 0; neg < 32; ++neg){
			if (total[neg] == '1'){
				total[neg] = '0';
			}else{
				total[neg] = '1';
			}
		}
	}
	printf("%s\n", total);
	
	printf("10987654321098765432109876543210\n");
}

// Sets the ith bit in *bitmap with the value in bitValue (0 or 1)
void setBitAt( unsigned int *bitmap, int i, int bitValue ) {
	if (bitValue == 1){
		bitValue = bitValue << i;
		bitmap[0] = bitmap[0] | bitValue;
	}
	if (bitValue == 0){
		bitValue = 1 << i;
		bitValue = ~bitValue;
		bitmap[0] = bitmap[0] & bitValue;
	}
}

// It returns the bit value (0 or 1) at bit i
int getBitAt( unsigned int bitmap, unsigned int i) {
	bitmap = bitmap >> i;
	if (bitmap%2 == 0){
		return 0;
	}else{
		return 1;
	}
}

// It returns the number of bits with a value "bitValue".
// if bitValue is 0, it returns the number of 0s. If bitValue is 1, it returns the number of 1s.
int countBits( unsigned int bitmap, unsigned int bitValue) {
	int count = 0;
	if (bitValue == 0){
		int i;
		for (i = 0; i < 32; ++i){
			int j = bitmap >> i;
			if (j%2 == 0){
				++count;
			}
		}
	}else{
		int i;
		for (i = 0; i < 32; ++i){
			int j = bitmap >> i;
			if (j%2 == 1){
				++count;
			}
		}
	
	}
	return count;
}

// It returns the number of largest consecutive 1s in "bitmap".
// Set "*position" to the beginning bit index of the sequence.
int maxContinuousOnes(unsigned int bitmap, int * position) {
	// Add your code here
}

