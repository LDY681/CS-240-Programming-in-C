#include <stdio.h>

int add(int a, int b);

int main(){
	printf("2 + 2 = %d\n", add(2, 2));
}

int add(int a, int b) {
	return a + b; 
}
