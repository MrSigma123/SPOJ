#include <stdio.h>
#include <stdlib.h>

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
	//printf("The answer is 42!\n");
	return 0;
}
