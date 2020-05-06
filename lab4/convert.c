#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Note: int sprintf(char *str, const char *format, additions)--composes a string
//char buffer[50]
//int n=sprintf (str, "%d plus %d is %d", a, b, a+b);	//str contains the string, n is the # of chars

//Function declaration
int convdec(char* num, int basefrom);	//Convert to dec, return dec number
int mypow(int base, int exp);	//homemade pow function since makefile doesnt include -lm

int main(int argc, char *argv[]){	//argc and argv
	//Argument missing condition
	if (argc != 4){		
		printf("Usage:  convert <basefrom> <baseto> <number>\n");	
		exit(1);
	}
	
	//grep variables from arg
	int basefrom = atoi(argv[1]);	//argv string to int
	int baseto = atoi(argv[2]);
	char *number = argv[3];
	

	//Number read in base basefrom: number
	printf("Number read in base %d: %s\n", basefrom, argv[3]);

	//base from 2 to 25
	if (baseto > 25 || baseto < 2 ||basefrom > 25 || basefrom < 2 ){
		printf("Incompatible base!\n");	//TODO
		exit(1);
	}

	//Wrong digit number!
	int abc = 0;
	while (argv[3][abc] != '\0'){
		if (argv[3][abc] >= 'A' && argv[3][abc] <= 'P'){
			if (argv[3][abc] - 'A' > basefrom - 10){
				printf("Wrong digit in number.\n");
				exit(1);
			}
		}else if (argv[3][abc] - '0' > basefrom){
			printf("Wrong digit in number.\n");
			exit(1);
		}
		++abc;
	}
		
	//convert to dec
	int conv = convdec(number, basefrom);
	printf("Converted to base 10: %d\n", conv);


	//convert dec to baseto
	int left = conv;	//left = number/baseto
	int remain = 0;	//Remainder
	char* store = (char*) malloc (50 * sizeof(char));
	int i = 0;
	while(left > 0){	//TODO: left = baseto case

		//store the remainder
		remain = left%baseto;
		switch(remain){
			case 10:
				store[i] = 'A';
				break;
			case 11:
				store[i] = 'B';
				break;
			case 12:
				store[i] = 'C';
				break;
			case 13:
				store[i]  = 'D';
				break;
			case 14:
				store[i] = 'E';
				break;
			case 15:
				store[i] = 'F';
				break;
			case 16:
				store[i] = 'G';
				break;
			case 17:
				store[i] = 'H';
				break;
			case 18:
				store[i] = 'I';
				break;
			case 19:
				store[i] = 'J';
				break;
			case 20:
				store[i] = 'K';
				break;
			case 21:
				store[i] = 'L';
				break;
			case 22:
				store[i] = 'M';
				break;
			case 23:
				store[i] = 'N';
				break;
			case 24:
				store[i] = 'O';
				break;
			case 25:
				store[i] = 'P';
				break;
			default:
				store[i] = remain + '0';

		}
		++i; 
		
		//do the division process
		left = left/baseto;			
	}
	store[i] = '\0';
	
	char* reverse = (char*) malloc (50 * sizeof(char));	//reverse the order of store
	int j;
	
	

	for (j = 0 ; j < i; ++j){
		reverse[j] = store[i-j -1];
	}
	reverse[i] = '\0';
	printf("Converted to base %d: %s\n", baseto, reverse);

return 0;	
}

//Function Definition
int convdec(char* num, int basefrom){
	
	//char *str = (char*) malloc ( 50 * sizeof(char));	//DONT FORGET TO MALLOC A NEW CREATED POINTER!!!
	//sprintf(str, "%d", num);
	//int len = strlen(str);
	int len = strlen(num);

	int i;
	int sum = 0;
	for (i = 0; i < len; ++i){
		if (num[i] >= 'A' && num[i] <= 'O'){
			sum = sum + ((num[i] - 'A') + 10)* mypow(basefrom, len - i -1);	//E.g. '5' - '0' = 5
		}else{
			sum = sum + (num[i] - '0')* mypow(basefrom, len - i -1);	//E.g. '5' - '0' = 5
		}
	}
return sum;
}

int mypow(int base, int exp){
	int i;
	int sum = 1;
	for (i = 0; i < exp; ++i){
	sum = sum*base;
	}
return sum;
}


