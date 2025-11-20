#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
int main(void) {
	char first;
	printf("enter character ");
	scanf("%c", &first);
	printf("%d", first);
	getchar();
	return 0;
}
