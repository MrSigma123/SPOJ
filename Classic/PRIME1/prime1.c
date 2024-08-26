/*
Peter wants to generate some prime numbers for his cryptosystem. Help him!
Your task is to generate all prime numbers between two given numbers!

Input

The input begins with the number t of test cases in a single line (t<=10).
In each of the next t lines there are two numbers m and n
(1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output

For every test case print all prime numbers p such that m <= p <= n,
one number per line, test cases separated by an empty line.

Example

Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
Warning: large Input/Output data, be careful with certain languages
(though most should be OK if the algorithm is well designed)
*/
#include <stdio.h>
#include <math.h>
int main (void)
{
  int test_cases;
  int i = 0;
  int j = 0;
  int test_value, divider, checked_value, value_divider_flag, lower_value, higher_value, limit;
  scanf("%d", &test_cases);
  // I can put all the max and min values into one one-dimensional array
  // (length 2*(max_value + min_value))
  int max_min_arr[test_cases*2];
  while (i < test_cases*2)
  {
    scanf("%d", &max_min_arr[i++]); // min value
    scanf("%d", &max_min_arr[i++]); // max value
  }
  printf("\n");
  // now array is filled with all test cases max an min values
  // it's the time to generate the prime number finder using
  // the data from just created array
  i = 0;                                // for lower limit value index
  value_divider_flag = 1;               // assuming the checked value is prime
  while (j < test_cases)
  {               // for specific test cases
    checked_value = max_min_arr[i++];   // minimal prime vale to start
    divider = 2;                        // assign minimal test value
    limit = max_min_arr[i++];           // assign max_value from range array
    while (checked_value <= limit)
    {
      while (divider <= sqrt(checked_value))
      {
        if (checked_value % divider == 0)
        {
          break;
        }
        divider++;
      }
      if (divider > sqrt(checked_value) && checked_value != 1) // it means the divider reached the prime value
        printf("%d\n", checked_value);
      checked_value++;
      divider = 2;
    }
    j++;
    printf("\n");
  }
  return 0;
}
