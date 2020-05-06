#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void private_array_check (const int *array);
extern void private_copy_init (char *block, int n);
extern void private_copy_check (const char *string);
extern void private_sort_check (const int *array);

void initialize_array ();
void copy_string ();
void bubble_sort ();
void test_token();

/*
 * Main simply calls each of the tests in turn.
 */
int main (int argc, char *argv[])
{
  test_token();
  printf ("Starting tests.\n");
  fflush (stdout);

  initialize_array ();
  
  copy_string ();
  
  bubble_sort ();

  return (0);
}

/*
 * This function allocates and initializes the array numbers[] to
 * contain the digits 1-4 and 0.
 */
void initialize_array ()
{
  int *numbers = NULL, i = 0;

  for (i = 0; i < 4; i++) {
    numbers[i] = i + 1;
  }
  numbers[4] = 0;

  private_array_check (numbers);
}

/*
 * This function copies a C string into an allocated buffer.
 */
void copy_string ()
{
  char string[] = "This is a string that I will copy.";
  char *copy;
  int i;
  int n = strlen (string) + 1;

  copy = malloc (n);
  private_copy_init (copy,n);
  
  for (i = 0; i < strlen (string); i++) {
    copy[i] = string[i];
  }
  
  printf ("Copied string: %s\n", copy);
  
  private_copy_check (copy);
  
  free (copy);
}

/*
 * This function takes an unsorted array of integers and
 * bubble sorts it.
 */
void bubble_sort ()
{
#define ARRAYSIZE 12
  int array[ARRAYSIZE] = { 5, 7, 99, 12, 42, 31, 1, 45, 9, 21, 22, 23 };
  int i, j, temp;
  
  for (i = ARRAYSIZE - 2; i > 0; i--) {
    for (j = i; j < ARRAYSIZE - 1; j++) {
      if (array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      } else {
        break;
      }
    }
  }
  
  private_sort_check (array);
}
