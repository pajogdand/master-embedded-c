/*
 * File Name   : 03-swap_numbers.c
 * Folder      : 00-basic
 *
 * Description :
 *  Implement 'swap_numbers' using bitwise operators in C.
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

#include <stdio.h>
#include <stdint.h>

// 3 = 0000 0011
// 5 = 0000 0101
// Step 1: a = a ^ b -> 6 = 0000 0110
// Step 2: b = a ^ b -> 3 = 0000 0011
// Step 3: a = a ^ b -> 5 = 0000 0101
int main(void)
{
    /* TODO: Implement logic here */

    printf("Program: %s\n", "swap_numbers");
    unsigned int a = 3; // Example input
    unsigned int b = 5; // Example input
    printf("Before Swap: a = %u, b = %u\n", a, b);
    a = a ^ b; // Step 1
    b = a ^ b; // Step 2
    a = a ^ b; // Step 3
    printf("After Swap: a = %u, b = %u\n", a, b);
    return 0;
}
