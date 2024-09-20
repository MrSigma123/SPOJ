/*
CPTTRN6 - Character Patterns (Act 6)
#basics

Given specified dimensions, print a grid-like pattern. Use the | (pipe) sign
to print vertical elements, the - (minus) to print horizontal ones and + (plus)
for crossings. The rest of the space fill with . (dots) characters.

Input

You are given t - the number of test cases and for each of the test cases four
positive integers: l - the number of horizontal elements, c - the number of
vertical elements in the grid; h and w - the high and the width of the single
rectangle respectively.

Output

For each of the test cases output the requested pattern (please have a look
at the example). Use one line break in between successive patterns.

Example

Input:
3
3 1 2 1
4 4 1 2
2 5 3 2

Output:
.|.
.|.
-+-
.|.
.|.
-+-
.|.
.|.
-+-
.|.
.|.

..|..|..|..|..
--+--+--+--+--
..|..|..|..|..
--+--+--+--+--
..|..|..|..|..
--+--+--+--+--
..|..|..|..|..
--+--+--+--+--
..|..|..|..|..


..|..|..|..|..|..
..|..|..|..|..|..
..|..|..|..|..|..
--+--+--+--+--+--
..|..|..|..|..|..
..|..|..|..|..|..
..|..|..|..|..|..
--+--+--+--+--+--
..|..|..|..|..|..
..|..|..|..|..|..
..|..|..|..|..|..

*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  int test_cases;
  int ** pattern_sizes_arr;
  int size = 10; // initial size for the number of cases
  int i, j, k, l, m;
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
    pattern_sizes_arr[i] = (int *)malloc(4 * sizeof(int));

    // check if the allocation succeed
    if (pattern_sizes_arr == NULL)
    {
      printf("Memory allocation failed!\n");
      return 1;
    }

    // read the input
    scanf("%d %d %d %d", &pattern_sizes_arr[i][0], &pattern_sizes_arr[i][1],
          &pattern_sizes_arr[i][2], &pattern_sizes_arr[i][3]);
  }
  // print the results
  for (i = 0; i < test_cases; i++) // for test cases
  {
    for (j = 0; j < pattern_sizes_arr[i][0]; j++) // for rows
    {
      for (k = 0; k < pattern_sizes_arr[i][2]; k++) // multiply subline row before separator
      {
        for (m = 0; m < pattern_sizes_arr[i][1]; m++) // pairs of dots and pipes in line
        {
          for (l = 0; l < pattern_sizes_arr[i][3]; l++)
          {
            printf(".");
          }
          printf("|");
        }
        for (l = 0; l < pattern_sizes_arr[i][3]; l++) // closing dots
        {
          printf(".");
        }
        printf("\n");
      }
      for (m = 0; m < pattern_sizes_arr[i][1]; m++) // pairs of minuses and pluses
      {
        for (l = 0; l < pattern_sizes_arr[i][3]; l++)
        {
          printf("-");
        }
        printf("+");
      }
      for (l = 0; l < pattern_sizes_arr[i][3]; l++) // closing dots
      {
        printf("-");
      }
      printf("\n");
      if (j == pattern_sizes_arr[i][0] - 1) // printing the closing row of dots and pipes w.o. separator
      {
        for (k = 0; k < pattern_sizes_arr[i][2]; k++) // multiply subline row
        {
          for (m = 0; m < pattern_sizes_arr[i][1]; m++) // pairs of dots and pipes in line
          {
            for (l = 0; l < pattern_sizes_arr[i][3]; l++)
            {
              printf(".");
            }
            printf("|");
          }
          for (l = 0; l < pattern_sizes_arr[i][3]; l++) // closing dots
          {
            printf(".");
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
