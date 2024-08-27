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
#include <stdlib.h>
#include <string.h>
int main(void)
{
  int cases;
  int i;
  char character;        // for testing
  char char_array[256];  // to store up to 200 characters
  char half_string[128]; // to store up to 100 characters
  scanf("%d", &cases);
  for(i = 0; i < cases; i++)
  {
    scanf("%255s", char_array);
    ...
    character = getchar();
    while(character != '\n')
    {

    }
    printf("%s\n", char_array);
  }
  return 0;
}

