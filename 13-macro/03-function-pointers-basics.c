#include <stdio.h>

// Define function pointer types for mathematical operations
typedef int (*operation_func)(int, int);

// Define a function for addition
int add(int a, int b) {
    return a + b;
}

int mul(int a, int b){
    return a*b;
}

int sub(int a, int b){
    return a-b;
}

int main() {
    // Declare a function pointer of type operation_func
    operation_func my_func;
    // my_func is function pointer who is going return int and take int variable as input

    // Assign the address of the add function to the function pointer
    my_func = add;

    // Use the function pointer to call the add function
    int result = my_func(5, 3);
    printf("Result: %d\n", result);  // Output: Result: 8


    my_func = sub;
    result = my_func(5,3);
    printf("Result=%d", result);

    return 0;
}
