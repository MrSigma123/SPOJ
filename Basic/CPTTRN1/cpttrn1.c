/*
CPTTRN1 - Character Patterns (Act 1)
#basics

Using two characters: . (dot) and * (asterisk) print a chessboard-like pattern.
The first character printed should be * (asterisk).

Input

You are given t < 100 - the number of test cases and for each of the test
cases two positive integers: l - the number of lines and c - the number of
columns in the pattern (l, c < 100).

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
*
.
*

*.*.
.*.*
*.*.
.*.*

*.*.*
.*.*.

*/
#include <stdio.h>
void display_pattern(int size1, int size2);

int main(void)
{
  int test_cases;
  int i, j;
  scanf("%d", &test_cases);
  int pattern_size[100][2]; // to store up to 100 pattern sizes

  for (i = 0; i < test_cases; i++) // enter the pattern sizes for all test cases
  {
    scanf("%d %d", &pattern_size[i][0], & pattern_size[i][1]);
  }

  for (i = 0; i < test_cases; i++) // display the patterns of the desired sizes
  {
    display_pattern(pattern_size[i][0], pattern_size[i][1]);
    if (i != test_cases - 1)
    {
      printf("\n");
    }
  }
  return 0;
}
void display_pattern(int size1, int size2)
{
  int i, j;
  for (i = 0; i < size1; i++)
  {
    for (j = 0; j < size2; j++)
    {
      if (i % 2 == 0)
      {
        if (j % 2 == 0)
          printf("*");
        else
          printf(".");
      }
      else
      {
        if (j % 2 == 0)
          printf(".");
        else
          printf("*");
      }
    }
    printf("\n");
  }
}
