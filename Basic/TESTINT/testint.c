/*
TESTINT - Test 1
#ad-hoc-1 #basics

Given two natural numbers (both not greater than 200), each number in the separate line, please print the sum of them.

Example

Input:
2
3

Output:
5
*/
#include <stdio.h>
int main(void)
{
  int value1, value2;
  scanf("%d", &value1);
  scanf("%d", &value2);
  if (value1 <= 200 && value2 <= 200)
  {
    printf("\n%d", value1 + value2);
  }
  return 0;
}
