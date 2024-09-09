/*
STRHH - Half of the half
#basics

Given a sequence of 2*k characters, please print every second character
from the first half of the sequence. Start printing with the first character.

Input

In the first line of input you are given the positive integer t (1<=t<=100)
- the number of test cases. In the each of the next t lines, you are given a
sequence of 2*k (1<=k<=100) characters.

Output

For each of the test cases please please print every second character from the first 
half of a given sequence (the first character should appear).

Example

Input:
4
your 
progress 
is 
noticeable

Output:
y
po
i
ntc
*/
#include <stdio.h>
int main(void)
{
  int t; // for storing test cases
  int i, j, str_length;
  char ch;
  scanf("%d ", &t);
  char string_array[100][200]; // for storing up to 100 strings of 200 ch. len
  char result_array[100][100]; // two times shorter string length
  for (i = 0; i < t; i++)      // test cases maneuvering
  {
    for (j = 0; ; j++)         // initializing the main string
    {
      ch = getchar();
      if (ch == '\n')
      {
        string_array[i][j] = '\0'; // indicate the end of the string
        break;
      }
      string_array[i][j] = ch;
    }
    str_length = j;
    for (j = 0; j < ((str_length / 2) + 1) / 2; j++) // initializing the results
    {
      result_array[i][j] = string_array[i][j*2];
    }
    result_array[i][j] = '\0';
  }
  printf("\n"); // separate the input from the output
  for (i = 0; i < t; i++)
  {
    for (j = 0; result_array[i][j] != '\0'; j++)
    {
      printf("%c", result_array[i][j]);
    }
    printf("\n");
  }
  return 0;
}
