#include <stdio.h>

// Define a macro to calculate the maximum of two numbers
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Define a macro to calculate the minimum of two numbers
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// Define a macro to calculate the square of a number
#define SQUARE(x) ((x) * (x))

int main() {
    int num1 = 10;
    int num2 = 20;

    // Calculate the maximum of num1 and num2 using the MAX macro
    int max = MAX(num1, num2);
    printf("The maximum of %d and %d is %d\n", num1, num2, max);

    // Calculate the minimum of num1 and num2 using the MIN macro
    int min = MIN(num1, num2);
    printf("The minimum of %d and %d is %d\n", num1, num2, min);

    // Calculate the square of num1 using the SQUARE macro
    int square = SQUARE(num1);
    printf("The square of %d is %d\n", num1, square);

    return 0;
}
