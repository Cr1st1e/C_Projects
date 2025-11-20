#define _CRT_NO_SECURE_DEPRECATE
#include <stdio.h>
void cleanInput(void);
void max3(void);
int main(void)
{
	printf("Enter sentence (cleans spaces): ");
	cleanInput();
	max3();
	getchar();
	return 0;
}
void cleanInput(void)
{
	char current, last = '\n';
	while ((current = getchar()) != '\n')
	{
		int isDoubleSpace = (last == ' ') && (current == ' ');
		int isLeadingSpace = (last == '\n') && (current == ' ');
	
		if ((last == ' ') && (current == '.')) // Remove space before period
			printf("\b.");
		else if (!isDoubleSpace && !isLeadingSpace) // Ignore double and leading spaces
			putchar(current);
		last = current;
	}
}
void max3(void) {
	int a , b, c;
	printf("enter 3 numbers");
	scanf_s(" %d%d%d",&a,&b,&c);
	int amax = (a > b) ? a : b;
	int max = (c > amax) ? c : amax;
	printf("max%d", max);

}
int binomial(int input) {
	int a=0, b=0, c;
	c = a + b;


}