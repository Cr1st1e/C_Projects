#include<stdio.h>

int main() {
	int s;
	s = 24 * 60 * 60;
	printf("number of seconds in a day % d\n", s);
	s = s * 7;
	printf("number of seconds in a week %d\n", s);
	s = 365 / 7;
	printf("number of weeks in a year %d\n", s);
	s = 365 % 7;
	printf("number of remaining days    %d\n", s);
	balance();
	first();
	int age;
	printf("Please enter your age: ");
	scanf_s("%d", &age);
	//getchar();
	printf("Age entered: %d\n", age);
	getchar();
	return 0;
}
int balance(void) {
	float b =1000;
	for (int i = 1; i <= 3; i++) {
		b = b +(b * 0.02);
		printf("the balance for year %d is %f \n", i, b);
	}
	
}