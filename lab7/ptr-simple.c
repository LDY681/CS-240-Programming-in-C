
#include <stdio.h>

int a; 
int *p; 
int b[20];

int
main() {
  a=5;
  p=&a;  

  printf("a=5\n");
  printf("p=&a\n");
  printf("a=%d\n",a);
  printf("&a=%ld\n",(long)&a);
  printf("p=%ld\n",(long)p); 
  printf("&p=%ld\n",(long)&p);
  printf("*p=%d\n",*p);

  printf("\n");

  p=&b[0];
  printf("&b[0]=%ld\n",(long)&b[0]);
  printf("p=%ld\n\n",(long)p);

  p++;
  printf("p++\n");
  printf("&b[1]=%ld\n",(long)&b[1]);
  printf("p=%ld\n\n",(long) p);

  p++;
  printf("p++\n");
  printf("&b[2]=%ld\n",(long) &b[2]);
  printf("p=%ld\n\n",(long)p);
  
  
}


