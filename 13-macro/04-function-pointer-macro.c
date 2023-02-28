#include <stdio.h>

// Define function pointer types for mathematical operations
typedef int (*operation_func)(int, int);

// Define a macro to create function pointer variables
#define DEFINE_OPERATION(name) operation_func name

// Define a macro to perform an operation using a function pointer
#define PERFORM_OPERATION(op, a, b) (op)((a), (b))

// Function for addition
int add(int a, int b) {
    return a + b;
}

// Function for subtraction
int subtract(int a, int b) {
    return a - b;
}

// Function for multiplication
int multiply(int a, int b) {
    return a * b;
}

// Function for division
int divide(int a, int b) {
    // Check for division by zero
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}

int main() {
    int num1 = 20;
    int num2 = 10;

    // Define function pointer variables using the macro
    DEFINE_OPERATION(add_op);
    DEFINE_OPERATION(subtract_op);
    DEFINE_OPERATION(multiply_op);
    DEFINE_OPERATION(divide_op);

    // Assign function pointers
    add_op = add;
    subtract_op = subtract;
    multiply_op = multiply;
    divide_op = divide;

    // Perform operations using function pointers and the macro
    printf("Addition: %d + %d = %d\n", num1, num2, PERFORM_OPERATION(add_op, num1, num2));
    printf("Subtraction: %d - %d = %d\n", num1, num2, PERFORM_OPERATION(subtract_op, num1, num2));
    printf("Multiplication: %d * %d = %d\n", num1, num2, PERFORM_OPERATION(multiply_op, num1, num2));
    printf("Division: %d / %d = %d\n", num1, num2, PERFORM_OPERATION(divide_op, num1, num2));

    return 0;
}
