/*
SMPSEQ3 - Fun with Sequences
#basics

You are given a sorted sequence of n integers S = s1, s2 ... sn and a sorted
sequence of m integers Q = q1, q2 ... qm.

Please print in ascending order all such si that does not belong to Q.

Input data specification

In the first line you are given one integer 2 <= n <= 100, and in the
following line n integers:
-100 <= si <= 100, si <= si+1.

In the third line you are given one integer 2 <= m <= 100, and in the
following line m integers:
-100 <= qi <= 100, qi <= qi+1.

Output data specification

The sequence of requested integers separated by spaces.

Example

Input:
5
-2 -1 0 1 4
6
-3 -2 -1 1 2 3

Output:
0 4
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  int n, m, i, j;
  int * array_n;
  int * array_m;
  scanf("%d", &n);
  array_n = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &array_n[i]);
  }
  scanf("%d", &m);
  array_m = (int *)malloc(sizeof(int) * m);
  for (i = 0; i < m; i++)
  {
    scanf("%d", &array_m[i]);
  }
  // ckecking value by value
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      if (array_n[i] == array_m[j])
      {
        break;
      }
      else if (array_n[i] < array_m[j])
      {
        printf("%d ", array_n[i]);
        break;
      }
      else if (array_n[i] > array_m[m-1] && array_m[j] == array_m[m-1])
      {
        printf("%d ", array_n[i]);
      }
    }
  }
  free (array_n);
  free (array_m);
  return 0;
}
