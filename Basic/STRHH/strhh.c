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
#define SIZE 101
int main(void){
  int cases, i, index, strlen;
  char string[SIZE];
  char result[SIZE]; // for simplicity
  int output_index = 0;
  scanf("%d", &cases);
  if (cases < 1 || cases > 100) return 0;
  for (i = 0; i < cases; i++){
    index = 0;
    strlen = 0;
    scanf("%s", string);
    //for finding the string length
    while (string[index++] != '\0'){
      strlen++;
    }
    //printf("%d", strlen);
    for (index = 0; index < strlen/2; index++){
      if (index % 2 == 0){
        //printf("%c", string[index]);
        result[output_index++] = string[index];
      }
    }
    //printf("\n");
    result[output_index++] = '\n';
    fflush(stdout);
  }
  result[output_index++] = '\0';
  output_index = 0;
  printf("\n");
  while(result[output_index] != '\0')
    printf("%c", result[output_index++]);
  return 0;
}
