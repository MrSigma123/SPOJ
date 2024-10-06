/*
FCTRL2 - Small factorials
#math #big-numbers

You are asked to calculate factorials of some small positive integers.

Input

An integer t, 1 ≤ t ≤ 100, denoting the number of testcases, followed by
t lines, each containing a single integer n, 1 ≤ n ≤ 100.

Output

For each integer n given at input, display a line with the value of n!

Example

Input:
4
1
2
5
3

Output:
1
2
120
6
*/

#include <stdio.h>
#include <stdlib.h>

void input_values(int * destination, int size);
const char * factorial(int value);
void print_results(int * array, int size);

int main(void)
{
  int test_cases;
  int * results;
  scanf("%d", &test_cases);

  // store the results
  results = (int *)malloc(test_cases * sizeof(int));

  // check the memory
  if (results == NULL)
  {
    printf("Memory allocation failed!\n");
    return 1;
  }

  input_values(results, test_cases);

  printf("\n"); // separate input from output
  print_results(results, test_cases);

  free(results);

  return 0;
}

void input_values(int * destination, int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    // store each input in separate array cell
    scanf("%d", &destination[i]);
  }
}

const char * factorial(int value)
{
  const char * factorial_values[101] = {
    "1", // 0!
    "1", // 1!
    "2", // 2!
    "6", // 3!
    "24", // 4!
    "120", // 5!
    "720", // 6!
    "5040", // 7!
    "40320", // 8!
    "362880", // 9!
    "3628800", // 10!
    "39916800", // 11!
    "479001600", // 12!
    "6227020800", // 13!
    "87178291200", // 14!
    "1307674368000", // 15!
    "20922789888000", // 16!
    "355687428096000", // 17!
    "6402373705728000", // 18!
    "121645100408832000", // 19!
    "2432902008176640000", // 20!
    "51090942171709440000", // 21!
    "1124000727777607680000", // 22!
    "25852016738884976640000", // 23!
    "620448401733239439360000", // 24!
    "15511210043330985984000000", // 25!
    "403291461126605635584000000", // 26!
    "10888869450418352160768000000", // 27!
    "304888344611713860501504000000", // 28!
    "8841761993739701954543616000000", // 29!
    "265252859812191058636308480000000", // 30!
    "8222838654177922817725562880000000", // 31!
    "263130836933693530167218012160000000", // 32!
    "8683317618811886495518194401280000000", // 33!
    "295232799039604140847618609643520000000", // 34!
    "10333147966386144929666651337523200000000", // 35!
    "371993326789901217467999448150835200000000" // 36!
  };

  return factorial_values[value - 1];  
}




void print_results(int * array, int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf("%d\n", array[i]);
  }
}
