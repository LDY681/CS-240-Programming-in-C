
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mymemdump(FILE * fd, char * p , int len) {
    // Add your code here.
    // You may see p as an array.
    // p[0] will return the element 0 
    // p[1] will return the element 1 and so on
 
	int i;	//for loop initial
	int ll = 0;	//len location
	while (ll < len){
		// Print address of the beginning of p. You need to print it every 16 bytes
		fprintf(fd, "0x%016lX: ", (unsigned long) p + ll);	//increment address
		// Print first byte as hexadecimal
		for (i = ll; i < len && i < ll + 16; i++){
			int c = p[i]&0xFF;
			fprintf(fd, "%02X ", c);
		}
	
		//Identation when less than 16 bytes
		int j = len;
		while (j < ll + 16){
			j++;
			fprintf(fd, "%s ", "  ");	//add space for no content blocks
		}
		
		fprintf(fd, "%s", " ");	//space between bytes and chars

		// Print first byte as character
		for (i = ll; i < len && i < ll + 16; i++){
			int c = p[i]&0xFF;
			fprintf(fd, "%c", (c>=32 && c < 127)?c:'.');
		}
		ll += 16;
		fprintf(fd,"\n");
	} 
}
     	
  	/*
	int i, j, k;
	for (j = 0; j < len/16; ++j){
		// Print address of the beginning of p. You need to print it every 16 bytes
		fprintf(fd, "0x%016lX: ", (unsigned long) p+ j *16);

			
		for (i = j*16; i < len && i < (j*16) +16; i++) {
			// Get value at [p]. The &0xFF is to make sure you truncate to 8bits or one byte.
			int c = p[i]&0xFF; 
       		 	// Print first byte as hexadecimal
        		fprintf(fd, "%02X ", c);
        	}

		
		fprintf(fd, "%s ", "");
		

   		for (i = j*16; i < len && i < (j*16) +16; i++) {
			// Get value at [p]. The &0xFF is to make sure you truncate to 8bits or one byte.
        		int c = p[i]&0xFF; 

       
        		// Print first byte as character. Only print characters >= 32 that are the printable characters.
        		fprintf(fd, "%c", (c >= 32 && c <= 127)?c:'.');
    		}
		fprintf(fd,"\n");
	}
	*/

