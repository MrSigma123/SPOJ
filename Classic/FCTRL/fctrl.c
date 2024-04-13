// This program is created to calculate the number of zeros contained in the factorial
// The solution based on calculations is very complex and temse towards the hardware
// so in orther to avoid straining the memory and CPU we may have just to use the factorial
// chart
// FACTORIAL CHART:
// 0! = 1
// 1! = 1
// 2! = 2
// 3! = 6
// 4! = 24
// 5! = 120
// 6! = 720
// 7! = 5040
// 8! = 40320
// 9! = 362880
// 10! =3628800
// Do you notice the pattern? Every factorial multiplied by multiplication of 5 add one zero,
// but after every fifth added zero there is one additional zero! 
// THIS PROGRAM IS DESIGNED TO WORK UP TO 100000 N VALUE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int inputValues();
int calculateAndPrintZerosCount(int factorialVal);
void printTheValues(int array[], int input);
int inputValues(){
  int input;
  scanf("%d", &input);
  return input;
}
int calculateAndPrintZerosCount(int factorialVal){
  int numberOfZeros = 0;
  int tmp = factorialVal;
  int i = 1;
  //numberOfZeros = factorialVal / 5;
  /*
  for (i = 0; i <= factorialVal; i++){
    if (i % 5 == 0)
      numberOfZeros++;
    if (numberOfZeros % 5 == 0 && numberOfZeros != 0)
      numberOfZeros++;
  }
  */
  /*
  numberOfZeros = factorialVal / 5 + factorialVal / 25 + factorialVal / 125 +
    factorialVal / 625 + factorialVal / 3125 + factorialVal / 15625 + factorialVal / 78125 +
    factorialVal / 390625 + factorialVal / 1953125 + factorialVal / 9765625
    + factorialVal / 48848125 + factorialVal / 244140625 + factorialVal / 1220703125;
  */
  for (tmp = factorialVal; pow(5,i) <= factorialVal; i++){
    numberOfZeros += tmp/pow(5,i);
  }

/*
  for (tmp = factorialVal; pow(5,i) <= factorialVal; i++){
    while (tmp >= pow(5,i)){
      tmp -= pow(5,i);
      numberOfZeros++;
    }
    tmp = factorialVal;
  }
  */
/*
  while (tmp > 5){
    while
    tmp /= pow(5, i);
    numberOfZeros++;
    i++;
  }
  while (factorialVal > 5){
    factorialVal -= 5;
    numberOfZeros++;
  }
  */
  return numberOfZeros;
}
void printTheValues(int array[], int input){
  int i;
  for(i = 0; i < input; i++){
    printf("%d\n", array[i]);
  }
}
int main(){
  int inputCount = inputValues();
  int i;
  int size = inputCount;
  int arrayOfInputs[size];
  for (i = 0; i < size; i++){
    scanf(" %d", &arrayOfInputs[i]);
  }
  int arrayOfResults[size];
  for(i = 0; i < size; i++){
    arrayOfResults[i] = calculateAndPrintZerosCount(arrayOfInputs[i]);
  }
  //printf("\n");
  printTheValues(arrayOfResults, size);
  return 0;
}
