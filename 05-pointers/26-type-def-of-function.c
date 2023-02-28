#include <stdio.h>

// Define a function pointer type
typedef int (*operation_ptr)(int, int);

// Define functions with the same signature as the function pointer type
int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int main()
{
    // Declare function pointer variables
    operation_ptr add_ptr, sub_ptr;

    // Assign functions to function pointers
    add_ptr = add;
    sub_ptr = subtract;

    // Call functions using function pointers
    printf("Result of add function: %d\n", add_ptr(3, 4));
    printf("Result of subtract function: %d\n", sub_ptr(3, 4));

    return 0;
}
