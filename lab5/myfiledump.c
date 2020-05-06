
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void filedump(char * p , int len) {
	int i;
	int ll = 0;	//len location
	while (ll < len){
		// Print address of the beginning of p. You need to print it every 16 bytes
		printf("0x%016lX: ", (unsigned long)  ll);	//increment address
		// Print first byte as hexadecimal
		for (i = ll; i < len && i < ll + 16; i++){
			int c = p[i]&0xFF;
			printf( "%02X ", c);
		}
	
		//Identation when less than 16 bytes
		int j = len;
		while (j < ll + 16){
			j++;
			printf("%s ", "  ");	//add space for no content blocks
		}
		
		printf("%s", " ");	//space between bytes and chars

		// Print first byte as character
		for (i = ll; i < len && i < ll + 16; i++){
			int c = p[i]&0xFF;
			printf("%c", (c>=32 && c < 127)?c:'.');
		}
		ll += 16;
		printf("\n");
	}
}

void main(int argc, char **argv) {
	if (argc < 2 ){
		printf("Usage: myfiledump file [maxbytes]\n");
		exit(1);
	}
	
	FILE * fin =  fopen(argv[1] , "r");	
	
	//Invalid file
	if (fin == NULL){
		printf("Error opening file \"%s\"\n", argv[1]);
		exit(1);	
	}


	//argv[] is char* || argv[][] is char
	int len = 0;
	if (argc >= 3){	//if have maxbytes
		len  = atoi(argv[2]);	//char to int

		fseek(fin, 0L, SEEK_END);  // Go to the end of the file fin
  		int len2 = ftell(fin); // Get current file pointer
   		fseek(fin, 0L, SEEK_SET); // Go back to the beginning of the file.
		
		if(len2 <= len){
			len = len2;
		
		}

	}else{	//if doesnt have maxbytes
		//get file sizes
		fseek(fin, 0L, SEEK_END);  // Go to the end of the file fin
  		len = ftell(fin); // Get current file pointer
   		fseek(fin, 0L, SEEK_SET); // Go back to the beginning of the file.	
	}
	
	char *p = (char*) calloc (len , sizeof(char));
	fread (p, 1, len, fin);
	filedump(p, len);	
}


