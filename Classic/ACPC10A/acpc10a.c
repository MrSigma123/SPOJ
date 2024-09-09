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
#include <stdlib.h>

int main(void)
{
    int i, cases = 0;
    int a1, a2, a3;
    int **input;  // Pointer to a dynamically allocated 2D array
    int size = 10;  // Initial size for the number of test cases

    // Allocate memory for the input array (array of pointers)
    input = (int **)malloc(size * sizeof(int *));
    
    // Check if the allocation succeeded
    if (input == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // store the input dynamically
    for (i = 0; ; i++)
    {
        // Reallocate memory if the number of test cases exceeds the initial size
        if (i >= size)
        {
            size *= 2;
            input = (int **)realloc(input, size * sizeof(int *));
            
            if (input == NULL)
            {
                printf("Memory allocation failed!\n");
                return 1;
            }
        }

        // Allocate memory for each test case (each row has 3 integers)
        input[i] = (int *)malloc(3 * sizeof(int));

        // Check if the allocation succeeded
        if (input[i] == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }

        // Read the input
        scanf("%d %d %d", &input[i][0], &input[i][1], &input[i][2]);

        // Check for the termination condition (0 0 0)
        if (input[i][0] == 0 && input[i][1] == 0 && input[i][2] == 0)
        {
            free(input[i]); // free the memory for the last case (0 0 0)
            break; // Stop reading when you encounter "0 0 0"
        }

        cases++; // count valid test cases
    }

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

    // Free the allocated memory
    for (i = 0; i < cases; i++)
    {
        free(input[i]); // Free each row
    }
    free(input); // Free the main array

    return 0;
}

