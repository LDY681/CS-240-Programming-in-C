#include <stdio.h>

char * mystrcat(char * dest, char * src)£»
int mystrlen(char * s);

void main() {
	char a[200];
	char * b;
	mystrcpy(a, "Hello world");
	b = mystrcat(a, ", CS240 C Programming");
	b = mystrcat(a, ", This is a great course");
	printf("\"%s\"\n", a);
	printf("\"%s\"\n", b);

	mystrcpy(a, "");
	b = mystrcat(a, "");
	b = mystrcat(b, "Hello");
	
	printf("\"%s\"\n", a);
	printf("\"%s\"\n", b);
}

int mystrlen(char * s){
	int len = 0; // string length
	int key = 0; // = 1 when need to break
	while (key == 0){
		if (s[len] != '\0'){
			++len;
		}else{ key = 1;}
	}

	return len;
}

char * mystrcat(char * dest, char * src){
	int lenofsrc = mystrlen(src);	//The length of src
	int lenofdest = mystrlen(dest);	//The length of dest
	int totallen = lenofdest + lenofsrc;
	char *concat = (char*) malloc (totallen * sizeof(char));
	
	int i = 0;	//Position
	while(i < totallen){
		if(i < lenofdest){
			concat[i] = dest[i];
		}else{ 
			concat[i] = src[i];
		}
		++i;
	}
	//concat[i] = '\0';
	return concat;
}

