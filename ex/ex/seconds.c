#include<stdio.h>

int main(void) {
	int s;
	s = 24 * 60 * 60;
	printf("number of seconds in a day % d\n", s);
	s = s * 7;
	printf("number of seconds in a week %d\n", s);
	s = 365 / 7;
	printf("number of weeks in a year %d\n", s);
	s = 365 % 7;
	printf("number of remaining days %d\n", s);
	return 0; 
}