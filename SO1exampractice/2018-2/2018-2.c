#define _CRT_SECURE_NO_DEPRECATE
#define N 16
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n;
	while (1)
	{
		printf("enter\n");
		if (scanf("%d", &n) == 1)
		{
			if ( n < 0 || n > N )
			{
				printf("too small or too large. retry\n");
				while (getchar() != '\n');
			}
			else 
			{
				int value = 1 << n;
				printf("%d \n", value);
				while (getchar() != '\n');
				break;
			}
		}
		else
		{
			printf("Invalid Input. Press anykey to quit");
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}