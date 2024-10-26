/*
ADDREV - Adding Reversed Numbers
#simple-math #ad-hoc-1

The Antique Comedians of Malidinesia prefer comedies to tragedies.
Unfortunately, most of the ancient plays are tragedies. Therefore
the dramatic advisor of ACM has decided to transfigure some tragedies
into comedies. Obviously, this work is very hard because the basic
sense of the play must be kept intact, although all the things change
to their opposites. For example the numbers: if any number appears in
the tragedy, it must be converted to its reversed form before being
accepted into the comedy play.

Reversed number is a number written in Arabic numerals but the order
of digits is reversed. The first digit becomes last and vice versa.
For example, if the main hero had 1245 strawberries in the tragedy,
he has 5421 of them now. Note that all the leading zeros are omitted.
That means if the number ends with a zero, the zero is lost by reversing
(e.g. 1200 gives 21). Also note that the reversed number never has any
trailing zeros.

ACM needs to calculate with reversed numbers. Your task is to add two
reversed numbers and output their reversed sum. Of course, the result
is not unique because any particular number is a reversed form of
several numbers (e.g. 21 could be 12, 120 or 1200 before reversing).
Thus we must assume that no zeros were lost by reversing (e.g. assume
that the original number was 12).

Input

The input consists of N cases (equal to about 10000). The first line
of the input contains only positive integer N. Then follow the cases.
Each case consists of exactly one line with two positive integers
separated by space. These are the reversed numbers you are to add.

Output

For each case, print exactly one line containing only one integer
- the reversed sum of two reversed numbers. Omit any leading zeros
in the output.

Example

Sample input: 
3
24 1
4358 754
305 794

Sample output:
34
1998
1
*/

#include <stdio.h>
#include <stdlib.h>

void reverse_number(int * value);
int main(void)
{
  int test_cases, i;
  int val1, val2, sum;
  int ** case_array;

  // input the number of test cases
  scanf("%d", &test_cases);

  // allocate the memory dynamically for test cases
  case_array = (int **)malloc(test_cases * sizeof(int *));
  
  // check if allocation was successful
  if (case_array == NULL)
  {
    printf("Memory allocation failed!\n");
    return 1;
  }
  
  // allocate the memory for each two specific numbers to be added
  for (i = 0; i < test_cases; i++)
  {
    case_array[i] = (int *)malloc(2 * sizeof(int));
    
    // check allocation for each pair
    if (case_array[i] == NULL)
    {
      printf("Memory allocation failed!\n");
      return 1;
    } 
  }

  // input the values
  for (i = 0; i < test_cases; i++)
  {
    scanf("%d%d", &case_array[i][0], &case_array[i][1]);
  }

  // display the values after reversing and reversing the result
  for (i = 0; i < test_cases; i++)
  {
    reverse_number(&case_array[i][0]);
    reverse_number(&case_array[i][1]);
    sum = case_array[i][0] + case_array[i][1];
    reverse_number(&sum);
    printf("%d\n", sum);
  }

  // free the memory
  for (i = 0; i < test_cases; i++)
  {
    free(case_array[i]);
  }

  free(case_array);

  return 0;
}

void reverse_number(int * value)
{
  int value_copy = *value;
  int reversed_number = 0;
  
  // return case for zero
  if (value_copy == 0)
  {
    return;
  }

  // cut trailing zeros
  while ((value_copy % 10) == 0)
  {
    value_copy /= 10;
  }

  while (value_copy != 0)
  {
    reversed_number += value_copy % 10;
    value_copy /= 10;
    if (value_copy != 0)
    {
      reversed_number *= 10;
    }
  }

  *value = reversed_number;
}
