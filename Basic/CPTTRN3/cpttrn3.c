/*
CPTTRN3 - Character Patterns (Act 3)
#basics

Using two characters: . (dot) and * (asterisk) print a grid-like pattern.

Input

You are given t - the number of test cases and for each of the test cases two
positive integers: l - the number of lines and c - the number of columns in the
grid. Each square of the grid is of the same size and filled with 4 dots
(see the example below).

Output

For each of the test cases output the requested pattern (please have a look at
the example). Use one line break in between successive patterns.

Example

Input:
3
3 1
4 4
2 5

Output:
****
*..*
*..*
****
*..*
*..*
****
*..*
*..*
****

*************
*..*..*..*..*
*..*..*..*..*
*************
*..*..*..*..*
*..*..*..*..*
*************
*..*..*..*..*
*..*..*..*..*
*************
*..*..*..*..*
*..*..*..*..*
*************

****************
*..*..*..*..*..*
*..*..*..*..*..*
****************
*..*..*..*..*..*
*..*..*..*..*..*
****************

*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  int test_cases;
  int ** pattern_sizes_arr;
  int size = 10; // initial size for the number of cases
  int i, j, k, l;
  scanf("%d", &test_cases);

  // allocate memory for the inpiut array (array of pointers)
  pattern_sizes_arr = (int **)malloc(size * sizeof(int *));

  // check if the allocation succeeded
  if (pattern_sizes_arr == NULL)
  {
    printf("Memory allocation failed!\n");
    return 1;
  }
  
  // store the input dynamically
  for (i = 0; i < test_cases; i++)
  {
    // reallocate memory if the number of test cases exceeds the initial size
    if (i >= size)
    {
      size *= 2;
      pattern_sizes_arr = (int **)realloc(pattern_sizes_arr, size * sizeof(int *));
    }

    if (pattern_sizes_arr == NULL)
    {
      printf("Memory allocation failed!\n");
      return 1;
    }

    // allocate the memory for each test case (each row has two integers)
    pattern_sizes_arr[i] = (int *)malloc(2 * sizeof(int));

    // check if the allocation succeed
    if (pattern_sizes_arr == NULL)
    {
      printf("Memory allocation failed!\n");
      return 1;
    }

    // read the input
    scanf("%d %d", &pattern_sizes_arr[i][0], &pattern_sizes_arr[i][1]);
  }
  // print the results
  for (i = 0; i < test_cases; i++)
  {
    for (j = 0; j < pattern_sizes_arr[i][0]; j++)
    {
      for (k = 0; k < pattern_sizes_arr[i][1]; k++)
      {
        // printing the first row of asterisks (only for j == 0 cases)
        if (j == 0 && k == 0)
        {
          for (l = 0; l < 4; l++)
          {
            printf("*");
          }
        }
        else if (j == 0 && k != 0)
        {
          for (l = 0; l < 3; l++)
          {
            printf("*");
          }
        }
      }
      printf("\n");
      // print the next two rows of the pattern
      for (l = 0; l < 2; l++)
      {
        for (k = 0; k < pattern_sizes_arr[i][1]; k++)
        {
          if (k == 0)
          {
            printf("*..*");
          }
          else
          {
            printf("..*");
          }
        }
        printf("\n");
      }
      // print the last row of the pattern
      for (k = 0; k < pattern_sizes_arr[i][1]; k++)
      {
        if (k == 0)
        {
          for (l = 0; l < 4; l++)
          {
            printf("*");
          }
        }
        else
        {
          for (l = 0; l < 3; l++)
          {
            printf("*");
          }
        }
      }
    }
    printf("\n");
    if (i != test_cases - 1)
    {
      printf("\n"); // separate the cases with exception of the last one
    }
  }

  // free the allocated memory
  for (i = 0; i < test_cases; i++)
  {
    free(pattern_sizes_arr[i]); // free each row
  }
  free(pattern_sizes_arr); // free the main array
  
  return 0;
}
