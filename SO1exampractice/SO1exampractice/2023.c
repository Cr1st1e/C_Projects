#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>

int keyboardInputNumberPoints(void);
/*point2D* generateRandomPoints(int numberPoints);
void printPoints(point2D* points, int numberPoints);
point2D getCenterOfGravity(point2D* points, int numberPoints);*/

int main() {

	int NumberOfPoints;
	NumberOfPoints= keyboardInputNumberPoints();
	printf("%lf", M_PI);
	getchar();
	return 0;
}



int keyboardInputNumberPoints(void)
{
	int NumberOfPoints;
	double a;
	printf("Enter number of 2D points to generate: ");
	while (1) {
		if (scanf("%d %lf", &NumberOfPoints,&a) != 2)
		{
			printf("Invalid input.Try again.\n");
			while (getchar() != '\n');
			printf("Enter number of 2D points to generate: ");
		}
		else if (NumberOfPoints < 1)
		{
			printf("Number must be positive.Try again.\n");
			while (getchar() != '\n');
			printf("Enter number of 2D points to generate: ");
		}
		else
		{
			printf("Numbers entered: %d   %lf\n", NumberOfPoints,a);
			return NumberOfPoints;
			while (getchar() != '\n');
			break;
		}
	}
}
