
#include <stdio.h>

void mymemdump(FILE *fd, char * p , int len);

int fact(int n) {
  int val;
  printf("fact(%d)\n", n);
  if (n == 1) {
      val = 1;
  }
  else {
  	val = n * fact(n-1);
  }
  mymemdump(stdout, (char*) &val,128);
  return val;
}

main()
{
	int v = fact(5);
	printf("fact(5)=%d\n", v);
}

