/*
TEST - Life, the Universe, and Everything
#basic #tutorial #ad-hoc-1

Your program is to use the brute-force approach in order to find the Answer
to Life, the Universe, and Everything. More precisely... rewrite small numbers
from input to output. Stop processing input after reading in the number 42.
All numbers at input are integers of one or two digits.

Example

Input:
1
2
88
42
99

Output:
1
2
88
Information

In case of any problems with your code, you can take a look in the forum,
you'll find the answer, only for this problem, in various languages.
*/
#include <stdio.h>
int main(void)
{
	int num;
	scanf("%d", &num);
	while (num != 42)
	{
	    if (num > 99 || num < 0)
	    {
	        printf("Try again with number in range 0-99\n");
	        scanf("%d", &num);
	    }
	    else
	    {
		    printf("%d\n", num);
		    scanf("%d", &num);
	    }
	}
	return 0;
}
