#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

int arraySum(int[], int size);

int main(void) 
{
	int array[3];
    printf("Enter\n");
    while (scanf("%d,%d,%d", &array[0], &array[1], &array[2]) != 3) {
        printf("Try Again\n");
        while (getchar() != '\n');
    }
	int sum = arraySum(array, 3);
	printf("%d", sum);
}
int arraySum(int arr[], int size) {
    if (size <= 0) {
        return 0; // Base case: if the array is empty, return 0
    }
    return arr[size - 1] + arraySum(arr, size - 1); // Recursive case: add the last element and recurse
}