
#include <stdio.h>
#include "stack.h"

int
main() 
{
  stack_clear();

  printf("Pushing values...\n");
  stack_push(5);
  stack_push(9);
  stack_push(2);
  stack_push(3);
  stack_print();
  printf("Pop values...\n");
  double x = stack_pop();
  double y = stack_pop();
  printf("x=%lf y=%lf\n", x, y);
  stack_print();
  printf("top=%d max=%d\n", stack_top(), stack_max());
  printf("isempty=%d", stack_is_empty());
  printf("Pop values...\n");
  stack_pop();
  stack_pop();
  stack_print();
  printf("top=%d max=%d\n", stack_top(), stack_max());
  printf("isempty=%d", stack_is_empty());
}

