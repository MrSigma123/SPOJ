/*
SIZECON - Size Contest
no tags 

Given the set of integers, find the sum of all positive integers in it.
Solutions can be sent in any language supported by SPOJ except Whitespace.

Input

t – number of test cases [t < 1000]
On each of next t lines given a integer N [-1000 <= N <= 1000]

Output

One integer equals to sum of all positive integers.

Score

Score equals to size of source code of your program except symbols with ASCII
code <= 32.

Example

Input:
4
5
-5
6
-1

Output:
11
*/
#include <stdio.h>
int main()
{
  int i, t, x, s = 0;
  scanf("%d", &t);
  for (i = 0; i < t; i++)
  {
    scanf("%d", &x);
    if (x > 0) s += x;
  }
  printf("%d", s);
  return 0;
}
