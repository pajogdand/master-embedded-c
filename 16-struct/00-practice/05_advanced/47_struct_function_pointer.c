/*
 * File Name   : 47_struct_function_pointer.c
 * Folder      : 05_advanced
 *
 * Program Name:
 *   Struct Function Pointer
 *
 * Description :
 *   Demonstrates use of function pointers
 *   inside a structure (callback mechanism).
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 47_struct_function_pointer.c -o 47_struct_function_pointer
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 *   - function pointers
 *   - embedded systems
 */

#include <stdio.h>

/* Function prototypes */
void add(int a, int b);
void subtract(int a, int b);

/* Structure Definition */
typedef struct
{
    int i;

    /* Function pointer inside structure */
    void (*operation)(int, int);
} my_struct;

/* Function Prototype */
void struct_function_pointer(void);

/* Main Function */
int main(void)
{
    struct_function_pointer();
    return 0;
}

/* Sample functions */
void add(int a, int b)
{
    printf("Addition = %d\n", a + b);
}

void subtract(int a, int b)
{
    printf("Subtraction = %d\n", a - b);
}

/* Function Definition */
void struct_function_pointer(void)
{
    my_struct s;

    s.i = 10;

    /* Assign function to function pointer */
    s.operation = add;
    s.operation(20, 10);

    /* Change function at runtime */
    s.operation = subtract;
    s.operation(20, 10);
}
