
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "stack.h"
#include "nextword.h"
#include "rpn.h"

int main(int argc, char ** argv)
{
  printf("RPN Calculator.\n");
  
  if (argc < 2) {
    printf("Usage: rpncalc filename [xvalue]\n");
    exit(1);
  }
  
  // Get file from first argument.
  char * fileName = argv[1];

  // Check if there is an x value passed as parameter
  double x = 0;
  if ( argc > 2) {
    sscanf(argv[2],"%lf", &x);
  }
  
  double result = rpn_eval(fileName,x);

  printf("Result: %lf\n", result);
}
