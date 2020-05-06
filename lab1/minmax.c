
#include <stdio.h>

main() {
	printf("Program that prints max and min of two numbers a,b\n");
	int a, b;
	int max,min;

	while (1) {
		printf("Type a and <enter>: ");
		scanf("%d",&a);
		getchar(); // Discard new line

		printf("Type b and <enter>: ");
		scanf("%d",&b);
		getchar(); // Discard new line

		if (a > b) {
			max = a;
			min = b;
		}
		else {
			max = b;
			min = a;
		}
		printf("max=%d min=%d\n",max,min);

		printf("Do you want to continue? Type y/n and <enter>");
		char answer;
		answer = getchar();

		if (answer=='n') {
			break;
		}	
	}
	printf("Bye\n");
}
	
