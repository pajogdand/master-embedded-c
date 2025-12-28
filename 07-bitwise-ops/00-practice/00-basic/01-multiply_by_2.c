/*
 * File Name   : 01-multiply_by_2.c
 * Folder      : 00-basic
 *
 * Description :
 *  Implement 'multiply_by_2' using bitwise operators in C.
 *
 * Requirement :
 *  - Use bitwise operators
 *  - Avoid arithmetic operators where applicable
 *  - Follow embedded C coding standards
 *
 * Sample Input :
 *  (Provide input via terminal or hardcoded values)
 *
 * Sample Output :
 *  (Expected output based on input)
 */

// 3      = 0000 0011
// 3 << 1 = 0000 0110 = 6

// 4      = 0000 0100
//4 << 1  = 0000 1000 = 8

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    /* TODO: Implement logic here */

    printf("Program: %s\n", "multiply_by_2");
    unsigned int number = 5; // Example input
    unsigned int result = number << 1;  // Multiply by 2 using left shift

    printf("Result of %u multiplied by 2 is: %u\n", number, result);

    return 0;
}
