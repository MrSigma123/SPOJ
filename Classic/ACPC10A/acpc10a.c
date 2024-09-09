/*
ACPC10A - What’s Next
no tags 

According to Wikipedia, an arithmetic progression (AP) is a sequence of numbers
such that the difference of any two successive members of the sequence is a
constant. For instance, the sequence 3, 5, 7, 9, 11, 13 ... is an arithmetic
progression with common difference 2. For this problem, we will limit ourselves
to arithmetic progression whose common difference is a non-zero integer.

On the other hand, a geometric progression (GP) is a sequence of numbers where
each term after the first is found by multiplying the previous one by a fixed
non-zero number called the common ratio.
For example, the sequence 2, 6, 18, 54 ... is a geometric progression with
common ratio 3. For this problem, we will limit ourselves to geometric
progression whose common ratio is a non-zero integer.

Given three successive members of a sequence, you need to determine the type
of the progression and the next successive member.

Input

Your program will be tested on one or more test cases. Each case is specified
on a single line with three integers (−10, 000 < a1, a2, a3 < 10, 000) where
a1, a2, and a3 are distinct.

The last case is followed by a line with three zeros.

Output

For each test case, you program must print a single line of the form:
XX v
where XX is either AP or GP depending if the given progression is an Arithmetic
or Geometric Progression. v is the next member of the given sequence. All input
cases are guaranteed to be either an arithmetic or geometric progressions.

Example

Input:
4 7 10
2 6 18
0 0 0

Output:
AP 13
GP 54
*/
#include <stdio.h>

int main(void)
{
    int i;
    int cases;
    int input[100][3]; // assume 100 test cases
    int a1, a2, a3; // declaring a1, a2, a3 at the beginning

    // store the input
    for (i = 0; i < 100; i++)
    {
        scanf("%d %d %d", &input[i][0], &input[i][1], &input[i][2]);
        if (input[i][0] == 0 && input[i][1] == 0 && input[i][2] == 0)
        {
            break; // Stop reading when you encounter "0 0 0"
        }
    }
    cases = i;

    // print the results
    for (i = 0; i < cases; i++)
    {
        a1 = input[i][0];
        a2 = input[i][1];
        a3 = input[i][2];

        if (a2 - a1 == a3 - a2)
        {
            printf("AP %d\n", a3 + (a2 - a1)); // add diff
        }
        else if (a2 / a1 == a3 / a2 && a2 % a1 == 0 && a3 % a2 == 0)
        {
            printf("GP %d\n", a3 * (a2 / a1)); // mult div
        }
    }

    return 0;
}

