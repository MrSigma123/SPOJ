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
  int arrayOfResults[input];
  for(i = 0; input > 0; input--, i++){
    arrayOfResults[i] = calculateAndPrintZerosCount();
  }
  printTheValues(arrayOfResults, i);
}