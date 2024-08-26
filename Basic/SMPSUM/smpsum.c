/*
SMPSUM - Iterated sums
#basics

Please compute the sum of squares for the given numbers: a, a+1, ..., b-1, b.

Input

Two numbers: a and b separated by space, where 1 <= a <= b <=100.

Output

Computed sum: a*a + (a+1)*(a+1) + ... + (b-1)*(b-1) + b*b

Example

Input:
1 4

Output:
30
Example 2

Input:
5 6

Output:
61
*/
#include <stdio.h>
int main(void)
{
  int a, b; // for storing the lower and upper range limits
  int sum = 0;
  scanf("%d %d", &a, &b);
  while (a <= b)
  {
    sum += a*a;
    a++;
  }
  printf("%d", sum);
  return 0;
}
