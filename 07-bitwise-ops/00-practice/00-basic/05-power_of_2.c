/*
 * File Name   : 05-power_of_2.c
 * Folder      : 00-basic
 *
 * Description :
 *  Implement 'power_of_2' using bitwise operators in C.
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

// Example:
// 2^0 = 1  = 0000 0001
// 2^1 = 2  = 0000 0010
// 2^2 = 4  = 0000 0100
// 2^3 = 8  = 0000 1000
// 2^4 = 16 = 0001 0000
// This can be achieved by left shifting 1 by 'n' positions to get 2^n

int main(void)
{
    /* TODO: Implement logic here */

    printf("Program: %s\n", "power_of_2");
    unsigned int n = 4; // Example input for 2^4
    unsigned int result = 1 << n;  // Calculate 2^n using left shift
    printf("2^%u = %u\n", n, result);
    return 0;
}
