/*
Input

Given a positive integer 0 < x < 50.

Output

Print one word: Wo...ow (letter o must be repeated x times).

Example 1

Input:
1

Output:
Wow
Example 2

Input:
7

Output:
Wooooooow
*/
#include <stdio.h>
int main(void){
  int cases;
  scanf("%d", &cases);
  printf("W");
  if (cases > 0 && cases < 50){
    while(cases > 0){
    printf("o");
    cases--;
    }
  }
  printf("w");
}
