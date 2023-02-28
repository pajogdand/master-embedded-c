#include <stdio.h>

int main(int argc, char *argv[]) {
    // argc is the argument count (number of arguments passed)
    // argv is an array of argument strings (array of character pointers)

    // Display the number of arguments passed
    printf("Number of arguments: %d\n", argc);

    // Loop through the arguments and display each one
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    // Check if there are at least 2 arguments (including the program name)
    if (argc > 1) {
        printf("\nFirst argument (after program name): %s\n", argv[1]);
    }

    // Perform a simple operation if at least 3 arguments are passed
    if (argc > 3) {
        // Assume arguments are integers for simplicity
        int num1 = atoi(argv[2]);
        int num2 = atoi(argv[3]);
        
        // Perform addition
        int sum = num1 + num2;
        
        // Display the result
        printf("\nAddition of %d and %d: %d\n", num1, num2, sum);
    }

    return 0;
}
