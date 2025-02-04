/*
SMPSEQ6 - Fun with Sequences (Act 4)
#simple-math #basics

You are given S - a sequence of n integers S = s1, s2 ... sn, Q - a sequence
of n integers Q = q1, q2 ... qn and a nonnegative parameter x.

Please print in ascending order all such i, that si = qi+y, where -x <= y <= x.

Input data specification

In the first line you are given two integers 2 <= n <= 100, 0 <= x < n and in
the following two lines n integers in each of the line:
-100 <= si, qi <= 100

Output data specification

The sequence of requested integers separated by spaces.

Example 1

Input:
5 2
-1 2 -1 1 -1
3 -2 -1 1 2

Output:
1 3 4 5
Example 2

Input:
6 4
-1 2 2 2 2 -2
3 -2 3 3 3 -1

Output:
6
Example 3

Input:
6 0
-1 2 10 12 6 -2
2 -2 10 21 6 -1
 
Output:
3 5
*/

#include <stdio.h>
#include <stdlib.h>

void scan_array(int * array, int size);

int main(void)
{
  int i, j;
  int string_size, param_x;
  int counter = 0;
  // set the string sizes and x parameter values
  scanf("%d", &string_size);
  scanf("%d", &param_x);

  // create two arrays for s and q strings
  int * string_s = (int*)malloc(sizeof(int) * string_size);
  int * string_q = (int*)malloc(sizeof(int) * string_size);
  int * results_string = (int*)malloc(sizeof(int) * string_size);

  // scan the arrays
  scan_array(string_s, string_size);
  scan_array(string_q, string_size);

  // find the indexes which match the condition
  for (i = 0; i < string_size && ((i + param_x) <= string_size - 1); i++)
  {
    // define quasi absolute value condition => -x >= y >= x
    if (i <= param_x)
    {
      for (j = -i; j <= param_x; j++)
      {
        if (string_s[i] == string_q[i] + j)
        {
          results_string[counter] = i + 1;
          counter++;
          break;
        }
      }
    }
    else
    {
      for (j = -param_x; j <= param_x && ((i + param_x) <= string_size - 1); j++)
      {
        if (string_s[i] == string_q[i] + j)
        {
          results_string[counter] = i + 1;
          counter++;
          break;
        }
      }
    }
  }

  // display the results
  for (i = 0; i < counter; i++)
  {
    printf("%d ", results_string[i]);
  }

  free(string_s);
  free(string_q);
  free(results_string);

  return 0;
}

void scan_array(int * array, int size)
{
  int i;

  for (i = 0; i < size; i++)
  {
    scanf("%d", array+i);  
  }

  return;
}
