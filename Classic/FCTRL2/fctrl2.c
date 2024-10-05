/*
FCTRL2 - Small factorials
#math #big-numbers

You are asked to calculate factorials of some small positive integers.

Input

An integer t, 1 ≤ t ≤ 100, denoting the number of testcases, followed by
t lines, each containing a single integer n, 1 ≤ n ≤ 100.

Output

For each integer n given at input, display a line with the value of n!

Example

Input:
4
1
2
5
3

Output:
1
2
120
6
*/

#include <stdio.h>
#include <stdlib.h>

int factorial(int value);
void print_results(int * array, int size);

int main(void)
{
  int test_cases;
  int * results;
  int i;
  scanf("%d", &test_cases);

  // store the results
  results = (int *)malloc(test_cases * sizeof(int));

  // check the memory
  if (results == NULL)
  {
    printf("Memory allocation failed!\n");
    return 1;
  }

  for (i = 0; i < test_cases; i++)
  {
    // store each input in separate array cell
    scanf("%d", &results[i]);
    // modify the input to achieve the factorial value
    results[i] = factorial(results[i]);
  }

  printf("\n"); // separate input from output
  print_results(results, test_cases);

  free(results);

  return 0;
}

int factorial(int value)
{
  int i;
  int result = 1;
  if (value == 0)
  {
    return 1;
  }
  else if (value == 1)
  {
    return 1;
  }
  else
  {
    for (i = 1; i <= value; i++)
    {
      result *= i;
    }
  }
  return result;
}

void print_results(int * array, int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf("%d\n", array[i]);
  }
}
