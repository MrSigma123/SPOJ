/*
SMPSEQ4 - Fun with Sequences (Act 2)
#basics

You are given a sorted sequence of n integers S = s1, s2 ... sn and a sorted
sequence of m integers Q = q1, q2 ... qm.

Please print in ascending order all such si that belongs to Q.

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
-2 -1 1 
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n, m, i, j;
  int * n_array;
  int * m_array;

  // allocate n memory size for n_array
  scanf("%d", &n);
  n_array = (int *)malloc(n * sizeof(int));

  // check memory allocation
  if (n_array == NULL)
  {
    printf("Memory allocation failed!\n");
    return 1;
  }

  // input n_array elements
  for (i = 0; i < n; i++)
  {
    scanf("%d", &n_array[i]);
  }

  // allocate m memory size for m_array
  scanf("%d", &m);
  m_array = (int *)malloc(m * sizeof(int));

  // check memory allocation
  if (m_array == NULL)
  {
    printf("Memory allocation failed!\n");
    return 1;
  }

  // input m_array elements
  for (i = 0; i < m; i++)
  {
    scanf("%d", &m_array[i]);
  }

  // compare the elements and print the common ones
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    { 
      if (n_array[i] == m_array[j])
      {
        printf("%d ", n_array[i]);
        break; // display the element if they match
      }
      if (n_array[i] < m_array[j])
      {
        break; // go compare next n_array element 
      }
    }
  }

  // free the memory
  free(n_array);
  free(m_array);

  return 0;
}
