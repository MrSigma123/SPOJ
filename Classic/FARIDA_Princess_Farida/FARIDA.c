/*
Once upon time there was a cute princess called Farida living in a castle with her father,
mother and uncle. On the way to the castle there lived many monsters. Each one of them had
some gold coins. Although they are monsters they will not hurt. Instead they will give you
the gold coins, but if and only if you didn't take any coins from the monster directly before
the current one. To marry princess Farida you have to pass all the monsters and collect as
many coins as possible. Given the number of gold coins each monster has, calculate the maximum
number of coins you can collect on your way to the castle.

Input

The first line of input contains the number of test cases. Each test case starts with a number N,
the number of monsters, 0 <= N <= 10^4. The next line will have N numbers, number of coins each
monster has, 0 <= The number of coins with each monster <= 10^9. Monsters described in the order
they are encountered on the way to the castle.

Output

For each test case print “Case C: X” without quotes. C is the case number, starting with 1.
X is the maximum number of coins you can collect.

Example

Input:
2
5
1 2 3 4 5
1
10

Output:
Case 1: 9
Case 2: 10
*/
/*
 The key is to add every second value and store it in results array
*/
#include <stdio.h>
#include <stdlib.h>
int main(void){
  int cases, numberOfDragons, numberOfCoins, check, i, j; //k
  long long int max = 0;
  //int smallerMax;
  long long int sum = 0;
  scanf("%d", &cases);
  if (cases == 0)
    return 0;
  long long int resultsArray[cases];
  for (i = 0; i < cases; i++){
    scanf("%d", &numberOfDragons);
    long long int dragonsCoinsArray[numberOfDragons];
    for (j = 0; j < numberOfDragons; j++){
      scanf("%lld", &dragonsCoinsArray[j]);
      printf("%lld\n", dragonsCoinsArray[j]);
    }
    //for (k = 0; k < numberOfDragons; k++){
      for (j = 0; j < numberOfDragons; j++){
        if (max < dragonsCoinsArray[j]){
          max = dragonsCoinsArray[j];
        printf("tutaj to działa\n");
        printf("%lld\n", max);
        }
      }
      printf("do kiego grzyba tego nie printuje!?\n");
      printf("%lld\n", max);
      sum += max;
      printf("sum == %lld\n", sum);
      check = max-1;
      while (check > 0){
      for (j = 0; j < numberOfDragons-1; j++){
        if (dragonsCoinsArray[j] == check
          && dragonsCoinsArray[j+1] != max){
        sum += check;
        max = check;
        check--;
        break;
        }
      }
      }
    printf("there was the %d iteration\n", i);
  //}
    resultsArray[i] = sum;
  }
  //printing results
  for (i = 0; i < cases; i++){
    printf("Case %d: %lld\n", i+1, resultsArray[i]);
  }
  return 0;
}
