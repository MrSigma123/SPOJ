// Prime Generator - 28.06.2023 2:21PM
// Peter wants to generate some prime numbers for his cryptosystem.
// Help him! Your task is to generate all prime numbers between two given numbers!
//
// Input
// The input begins with the number t of test cases in a single line (t<=10).
// In each of the next t lines there are two numbers m and
// n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.
// Output
// For every test case print all prime numbers p such that m <= p <= n,
// one number per line, test cases separated by an empty line.
// Example
// Input:
// 2
// 1 10
// 3 5

//Output:
// 2
// 3
// 5
// 7
//
// 3
// 5
//
// check n-m<=100000 condition
#include <stdlib.h>
#include <stdio.h>
void printPrimeValues(int *primeArray, int index);
int main(void){
  int cases;
  int max_range, min_range;
  int iterator, value, division_test;
  short int flag = 0;
  int *primeArray;
  int primeArrayIndex = 0;
  primeArray = malloc(sizeof(int)*100000);
  scanf("%d", &cases);
  if (cases > 10) // quit if range is too great
    return 0;
  for (iterator = 0; iterator < cases; iterator++){
    scanf("%d", &min_range);
    scanf("%d", &max_range);
    for (value = min_range; value < max_range; value++){
      for (division_test = 2; division_test < value; division_test++){
        if (value % division_test+1 != 0)
          continue;
        else{
          flag = 1;
          primeArray[primeArrayIndex] = value;
          primeArrayIndex++;
        }
      }
    }
  }
  printPrimeValues(primeArray, primeArrayIndex);
  free primeArray;
  return 0;
}
// add variable length array! to store the prime numbers
void printPrimeValues(int *primeArray, int index){
  int i = 0;
  for (i = 0; i < index; i++){
    printf("%d\n", primeArray[i]);
  }
}
