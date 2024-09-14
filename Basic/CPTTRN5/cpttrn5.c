// CPTTRN5 - Character Patterns (Act 5)
// #basics
//
// Using two characters: . (dot) and * (asterisk) print a grid-like pattern.
// The grid will have l lines, c columns, and each square shaped element of
// the grid will have the height and width equal to s.
//
// Moreover, each of the grid elements will have a diagonal. The diagonal of
// the first square in the first line of the grid is directed towards down and
// right corner - use the \ (backslash) character to print it; while the next diagonal will be directed towards upper right corner - use the / (slash) character to print it. Print the successive diagonals alternately (please consult the example below).
//
// Input
//
// You are given t - the number of test cases and for each test case three
// positive integers: l - the number of lines, c - the number of columns in
// the grid and s - the size of the single square shaped element.
//
// Output
//
// For each of the test cases output the requested pattern (please have a
// look at the example). Use one line break in between successive patterns.
//
// Example
//
// Input:
// 3
// 3 1 2
// 4 4 1
// 2 5 2
//
// Output:
// ****
// *\.*
// *.\*
// ****
// *./*
// */.*
// ****
// *\.*
// *.\*
// ****
//
// *********
// *\*/*\*/*
// *********
// */*\*/*\*
// *********
// *\*/*\*/*
// *********
// */*\*/*\*
// *********
//
// ****************
// *\.*./*\.*./*\.*
// *.\*/.*.\*/.*.\*
// ****************
// *./*\.*./*\.*./*
// */.*.\*/.*.\*/.*
// ****************
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

    // allocate the memory for each test case (each row has three integers)
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
  for (i = 0; i < test_cases; i++)
  {
    for (j = 0; j < pattern_sizes_arr[i][0]; j++)
    {
      for (k = 0; k < pattern_sizes_arr[i][1]; k++)
      {
        // print the first line of asterisks
        if (j == 0 && k == 0)
        {
          for (l = 0; 
            l < pattern_sizes_arr[i][2] + 2;
            l++)
          {
            printf("*");
          }
        }
        else if (j == 0 && k != 0)
        {
          for (l = 0;
            l < pattern_sizes_arr[i][2] + 1;
            l++)
          {
            printf("*");
          }
        }
      }
      if (j == 0)
      {
        printf("\n");
      }
      // printing the inner part of the patters
      for (l = 0; l < pattern_sizes_arr[i][2]; l++)
      {
        for (k = 0; k < pattern_sizes_arr[i][1]; k++)
        {
          if (k == 0)
          {
            printf("*");
            for (m = 0; m < pattern_sizes_arr[i][2]; m++)
            {
              if ((j + k) % 2 == 0) // for backslash inner pattern
              {
                if (pattern_sizes_arr[i][2] == 1)
                {
                  printf("\\");
                  break;
                }
                else if (m == l)
                {
                  printf("\\");
                }
                else
                {
                  printf(".");
                }
              }
              else // for standard slash inner pattern
              {
                if (pattern_sizes_arr[i][2] == 1)
                {
                  printf("/");
                  break;
                }
                else if (m != l)
                {
                  printf("/");
                }
                else
                {
                  printf(".");
                }
              }
            }
            printf("*");
          }
          else // k != 0
          {
            for (m = 0; m < pattern_sizes_arr[i][2]; m++)
            {
              if ((j + k) % 2 == 0) // for backslash inner pattern
              {
                if (pattern_sizes_arr[i][2] == 1)
                {
                  printf("\\");
                  break;
                }
                if (m == l)
                {
                  printf("\\");
                }
                else
                {
                  printf(".");
                }
              }
              else // for standard slash inner pattern
              {
                if (pattern_sizes_arr[i][2] == 1)
                {
                  printf("/");
                  break;
                }
                if (m != l)
                {
                  printf("/");
                }
                else
                {
                  printf(".");
                }
              }
            }
            printf("*");
          }
        }
        printf("\n");
      }
      // printing the closing line of the patters
      for (k = 0; k < pattern_sizes_arr[i][1]; k++)
      {
        // print the first line of asterisks
        if (k == 0)
        {
          for (l = 0; 
            l < pattern_sizes_arr[i][2] + 2;
            l++)
          {
            printf("*");
          }
        }
        else // k != 0
        {
          for (l = 0;
            l < pattern_sizes_arr[i][2] + 1;
            l++)
          {
            printf("*");
          }
        }
      }
      printf("\n");
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
