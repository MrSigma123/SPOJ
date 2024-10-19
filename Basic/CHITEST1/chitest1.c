/*
CHITEST1 - Sum of two numbers
no tags 

Compute the sum of two numbers.

Input

The first line of the input will include the number N of test cases,
and the each of the following N lines will include two numbers separated
by whitespace.

Output

Starting with the second line of the input, the sum of the two numbers
in the line must be printed into a line in the output. The accuracy of
the output should be better than 10^-6.

Example

Input:
3 
2 3
3.3 4
-1 4

Output:
5
7.3
3
*/

#include <stdio.h>
#include <stdlib.h>

int display_results(double * array, int size);

int main(void)
{
  int i;
  int test_cases;
  double value1, value2;
  double * results_array;
  scanf("%d", &test_cases);

  // allocate the memory
  results_array = (double *)malloc(test_cases * sizeof(double));

  // check the memory
  if (results_array == NULL)
  {
    printf("Memory allocation failed!\n");
    return 1;
  }

  // enter the results
  for (i = 0; i < test_cases; i++)
  {
    scanf("%lf %lf", &value1, &value2);
    results_array[i] = value1 + value2;
  }

  // display the results
  display_results(results_array, test_cases);

  // free the memory
  free(results_array);

  return 0;
}

int display_results(double * array, int size)
{
  if (array == NULL)
  {
    return 1;
  }

  int i;

  for (i = 0; i < size; i++)
  {
    printf("%lf\n", array[i]);
  }

  return 0;
}
