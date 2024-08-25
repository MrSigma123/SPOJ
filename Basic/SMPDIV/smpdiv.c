/* 
SMPDIV - Divisibility
#simple-math #ad-hoc-1 #basics

Print all integers ai such that ai is divisible by x and not divisible by y, where 1 < ai < n < 100000.

Input

First, you are given t (t < 100) - the number of test cases. In each of the following t lines, 3 integers: n x y.

You might assume also that x < n and x is not divisible by y.

Output

In each of the following t lines, numbers requested in the problem description in the separated by a single space in ascending order.

Example

Input:
2
7 2 4
35 5 12
Output:
2 6
5 10 15 20 25 30
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  int r = 100000;    // range
  int n, x, y;       // limt, divisor, not divisor
  int t;             // test cases
  int a = 2;         // tested value started from 2
  int i;
  int j = 0;
  scanf("%d", &t);
  int * input_array = (int*)malloc(t * sizeof(int) * 3);
  for (i = 0; i < t; i++)
  {
    scanf("%d %d %d", &n, &x, &y); 
    input_array[j] = n;
    j++;
    input_array[j] = x;
    j++;
    input_array[j] = y;
    j++;
  }
  j = 0; // reset the jterator
  // results
  for (i = 0; i < t; i++)
  {
    while (a < input_array[j])
    {
      if (a % input_array[j+1] == 0 && a % input_array[j+2] != 0)
      {
        printf("%d ", a);
      }
      a++;
    }
    j = j + 3;
    a = 2;
    printf("\n");
  }
  free(input_array);
  return 0;
}
