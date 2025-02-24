#include <stdio.h>
#include <math.h>

// Function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n, i, j;
    float x[20], y[20][20], value, h, u, result;

    // Input number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Input the data points
    printf("Enter the values of x:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter the values of y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &y[i][0]);
    }

    // Calculate backward differences
    for (j = 1; j < n; j++) {
        for (i = n - 1; i >= j; i--) {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }

    // Display the backward difference table
    printf("\nBackward Difference Table:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f", x[i]);
        for (j = 0; j <= i; j++) {
            printf("\t%.2f", y[i][j]);
        }
        printf("\n");
    }

    // Input the value to interpolate
    printf("\nEnter the value of x to interpolate: ");
    scanf("%f", &value);

    // Initialize variables
    h = x[1] - x[0]; // Step size
    u = (value - x[n - 1]) / h; // u value
    result = y[n - 1][0]; // Start with the last y value

    // Calculate interpolation result
    for (i = 1; i < n; i++) {
        float term = u;
        for (j = 1; j < i; j++) {
            term *= (u + j);
        }
        result += (term * y[n - 1][i]) / factorial(i);
    }

    printf("\nInterpolated value at x = %.2f is %.2f\n", value, result);

    return 0;
}