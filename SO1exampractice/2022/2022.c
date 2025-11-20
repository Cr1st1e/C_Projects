#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

// Function to compute the sine of x * PI using the series expansion
double sine(double x, int K) {
    double result = x * M_PI; // Initialize result with x * PI
    for (int n = 1; n <= K; n++) {
        result *= (1 - (x * x) / (n * n)); // Multiply by (1 - x^2 / n^2)
    }
    return result;
}

// Function to compute the principal value of x (0 <= principal value < 2 * PI)
double principalValue(double x) {
    double twoPi = 2 * M_PI;
    double principal = fmod(x, twoPi); // Use fmod to get the remainder
    if (principal < 0) {
        principal += twoPi; // Ensure the result is in [0, 2 * PI)
    }
    return principal;
}

int main() {
    double x;
    int K;
    char choice;

    printf("Series expansion for sin(x * PI) with k > 0 terms.\n");

    do {
        // Prompt user for input
        printf("Please enter <x>,<k>: ");
        while (scanf("%lf %d", &x, &K) != 2 || K < 1) {
            // Clear the input buffer if input is invalid
            while (getchar() != '\n');
            printf("Invalid input. Retry: ");
        }
        while (getchar() != '\n'); // Clear the input buffer after valid input

        // Print approximations for k = 1 to K
        printf("Approximations of sin(%.2f * pi):\n", x);
        for (int i = 1; i <= K; i++) {
            double approx = sine(x, i);
            printf(" k = %d: sin(x * PI) = %lf\n", i, approx);
        }

        // Compute and print the principal value of x * PI
        double principal = principalValue(x * M_PI);
        printf("Principal value: %.2f * pi\n", principal / M_PI);

        // Ask user to quit or continue
        printf("Enter <q> to quit, any other key to continue: ");
        choice = getchar();
        while (getchar() != '\n'); // Clear the input buffer

    } while (choice != 'q' && choice != 'Q');

    return 0;
}