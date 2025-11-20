#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>
#include "2018.h"
#include <stdlib.h>

void printArray(const int* Array, int size);
int* cloneArray(const int orginal[], int size);
int main(void) {
	int Original[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	char str[] = { "Myo Min Naing" };
	int size;
	int* clone;
	size = sizeof(Original) / sizeof(int);
	printArray(Original, size);
	clone = cloneArray(Original, size);
	for (int i = 0;i < size;i++) {
		printf("%d  ", clone[i]);
	}

	getchar(); // Last scanf() could not read character
	free(clone);
	getchar();
	return 0;
}
void printArray(const int* array, int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int* cloneArray(const int orginal[],int size) {
	int* clone = (int*)malloc(size * sizeof(int));
	if (clone == NULL) {
		printf("memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	int k = size;
	for (int i = 0;i < size;i++) {
		clone[i] = orginal[k-1];
		k--;
	}
	return clone;
}