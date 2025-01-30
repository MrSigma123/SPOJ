/*
SMPSEQ5 - Fun with Sequences (Act 3)
#simple-math #basics

You are given a sequence of n integers S = s1, s2 ... sn and a sequence of m
integers Q = q1, q2 ... qm.

Please print in ascending order all such i, that si = qi, i<=n, i<=m.

Input data specification

In the first line you are given one integer 2 <= n <= 100, and in the
following line n integers:
-100 <= si <= 100, si <= si+1.

In the third line you are given one integer 2 <= m <= 100, and in the
following line m integers:
-100 <= qi <= 100, qi <= qi+1.

Output data specification

The sequence of requested indexes separated by spaces.

Example 1

Input:
5
-2 -2 -1 1 4 
6
-3 -2 -1 1 2 3

Output:
2 3 4
Example 2

Input:
5
-2 -1 -3 1 4 
5
-3 -2 -1 1 2

Output:
4
*/

#include <stdio.h>
#include <limits.h>
int main(void)
{
  // define variables
  int i;
  int x = 0;  // result array starting index
  int test_cases_n;
  int test_cases_m;
  int index_limit;

  // scan the first string
  scanf("%d", &test_cases_n);
  int array_n[test_cases_n];
  for (i = 0; i < test_cases_n; i++)
  {
    scanf("%d", &array_n[i]);
  }
  
  // scan the second string
  scanf("%d", &test_cases_m);
  int array_m[test_cases_m];
  for (i = 0; i < test_cases_m; i++)
  {
    scanf("%d", &array_m[i]);
  }
  
  // set the limiter
  if (test_cases_m > test_cases_n)
  {
    index_limit = test_cases_m;
  }
  else
  {
    index_limit = test_cases_n;
  }

  // define result string storaga
  int result_string_storage[index_limit];

  // check the inexes match
  for (i = 0; i < index_limit; i++)
  {
    if (array_n[i] == array_m[i])
    {
      result_string_storage[x] = array_n[i];
      x++;
    }
  }

  // sort the results (implement own sorting algorithm)
  int minimum = INT_MAX;
  for (i = 0; i < x; i++)
  {

  }

  return 0;
}

