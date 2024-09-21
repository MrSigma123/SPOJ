/*
CPTTRN7 - Character Patterns (Act 7)
#basics

Print a regular grid pattern with diamond-like base elements. Use the \ (backslash) and the / (slash) characters to print diamonds and . (dots) to fill the rest of the space.

Input

You are given t - the number of test cases and for each of the test cases three positive integers: r - the number of rows, c - the number of columns in the grid and s - the size of each diamond.

Output

For each of the test cases output the requested pattern (please have a look at the example). Use one line break in between successive patterns.

Example

Input:
3
3 1 2
4 4 1
2 5 2

Output:
./\.
/..\
\../
.\/.
./\.
/..\
\../
.\/.
./\.
/..\
\../
.\/.

/\/\/\/\
\/\/\/\/
/\/\/\/\
\/\/\/\/
/\/\/\/\
\/\/\/\/
/\/\/\/\
\/\/\/\/

./\../\../\../\../\.
/..\/..\/..\/..\/..\
\../\../\../\../\../
.\/..\/..\/..\/..\/.
./\../\../\../\../\.
/..\/..\/..\/..\/..\
\../\../\../\../\../
.\/..\/..\/..\/..\/.

*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  int test_cases;
  int **pattern_sizes_arr;
  int size = 10; // initial size for the number of cases
  int i, j, k, l, m, n;
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
    // allocate the memory for each test case (each row has four integers)
    pattern_sizes_arr[i] = (int *)malloc(3 * sizeof(int));
    
    // check if the allocation succeed
    if (pattern_sizes_arr == NULL)
    {
      printf("Memory allocation failed!\n");
      return 1;
    }
    // read the input
    scanf("%d %d %d", &pattern_sizes_arr[i][0], &pattern_sizes_arr[i][1],
          &pattern_sizes_arr[i][2]);
  }

  // print the results
  for (i = 0; i < test_cases; i++) // for each case
  {
    for (j = 0; j < pattern_sizes_arr[i][0]; j++) // for each row
    {
      for (k = 0; k < pattern_sizes_arr[i][1]; k++) // for each column
      {
        for (n = 0; n < pattern_sizes_arr[i][2]; n++) // for repeating U part of pattern line
        {
          for (l = 0; l < pattern_sizes_arr[i][2]; l++) // for diagonal UL part of pattern
          {
            for (m = 0; m < pattern_sizes_arr[i][2] / 2; m++)
            {
              if (l + m + n == pattern_sizes_arr[i][2] - 1) 
              {
                printf("/");
              }
              else
              {
                printf(".");
              }
            }
          }
          for (l = 0; l < pattern_sizes_arr[i][2]; l++) // for diagonal UR part of pattern
          {
            for (m = 0; m < pattern_sizes_arr[i][2] / 2; m++)
            {
              if (l - n == m)
              {
                printf("\\");
              }
              else
              {
                printf(".");
              }
            }
          }
          printf("\n");
        }

      }

      for (k = 0; k < pattern_sizes_arr[i][1]; k++)
      {
        for (n = 0; n < pattern_sizes_arr[i][2]; n++) // for repeating D part of pattern line
        {
          for (l = 0; l < pattern_sizes_arr[i][2]; l++) // for diagonal DL part of pattern
          {
            for (m = 0; m < pattern_sizes_arr[i][2] / 2; m++)
            {
              if (l - n == m)
              {
                printf("\\");
              }
              else
              {
                printf(".");
              }
            }
          }
          for (l = 0; l < pattern_sizes_arr[i][2]; l++) // for diagonal DR part of pattern
          {
            for (m = 0; m < pattern_sizes_arr[i][2] / 2; m++)
            {
              if (l + m + n == pattern_sizes_arr[i][2] - 1) 
              {
                printf("/");
              }
              else
              {
                printf(".");
              }
            }
          }
          printf("\n");
        }

      }

    }

    if (i < test_cases - 1)
    {
      
      printf("\n");
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
