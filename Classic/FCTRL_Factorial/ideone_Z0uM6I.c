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
int inputValues();
int calculateAndPrintZerosCount();
void printTheValues(int array[], int input);
int inputValues(){
  int input;
  scanf("%d", &input);
  return input;
}
int calculateAndPrintZerosCount(){
  int value;
  int numberOfZeros;
  scanf("%d", &value);
  numberOfZeros = value / 5 + value / 25 + value / 125 +
    value / 625 + value / 3125 + value / 15625 + value / 78125 +
    value / 390625 + value / 1953125;
  // if(numberOfZeros > 5){
  //  int i;
  //  additionalZeros = numberOfZeros;
  //  for(i = 0; additionalZeros >= 5; i++){  
  //    additionalZeros = additionalZeros - 5;
  //  }numberOfZeros += (additionalZeros + additionalZeros2);
  // }
  return numberOfZeros;
}
void printTheValues(int array[], int input){
  int i;
  for(i = 0; i < input; i++){
    printf("%d\n", array[i]);
  }
}
int main(){
  int input = inputValues();
  int i;
  int size = input;
  int arrayOfResults[size];
  for(i = 0; input > 0; input--, i++){
    arrayOfResults[i] = calculateAndPrintZerosCount();
  }
  printTheValues(arrayOfResults, size);
  return 0;
}
