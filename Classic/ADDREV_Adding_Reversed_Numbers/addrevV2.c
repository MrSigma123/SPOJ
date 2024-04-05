#include <stdio.h>
#include <stdlib.h>
// V2 of addrev program functinality
// looking to fix memory leak
int main(void){
  unsigned int count, value1, value2, sum;
  unsigned int invertedValue1, invertedValue2;
  unsigned int invertedSum;
  int trailingZerosFlag, i;
  scanf("%u", &count); // for N input values
  unsigned int resultArray[count];
  for (i = 0; i < count; i++){
    sum = 0;
    trailingZerosFlag = 0;
    invertedValue1 = 0;
    invertedValue2 = 0;
    invertedSum = 0;
    scanf("%u %u", &value1, &value2);
    while (value1 > 0){
      if (value1 % 10 == 0 && trailingZerosFlag == 0){
        value1 /= 10;
        continue;
      }
      trailingZerosFlag = 1;
      invertedValue1 += value1 % 10;
      if (value1 > 10)
        invertedValue1 *= 10;
      value1 /= 10;
    }
    while (value2 > 0){
      if (value2 % 10 == 0 && trailingZerosFlag == 0){
        value2 /= 10;
        continue;
      }
      trailingZerosFlag = 1;
      invertedValue2 += value2 % 10;
      if (value2 > 10)
        invertedValue2 *= 10;
      value2 /= 10;
    }
    sum = sum + invertedValue1 + invertedValue2;
    while (sum > 0){
      if (sum % 10 == 0 && trailingZerosFlag == 0){
        sum /= 10;
        continue;
      }
      trailingZerosFlag = 1;

    }
  }
  return 0;
}
