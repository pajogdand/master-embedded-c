/*
 * File Name   : 08-multiply_using_bitwise.c
 * Folder      : 04-tricky
 *
 * Description :
 *  Implement 'multiply_using_bitwise' using bitwise operators in C.
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

int main(void)
{
    /* TODO: Implement logic here */

    unsigned int a = 6; // Example input (6)
    unsigned int b = 7; // Example input (7)
    unsigned int result = 0; // To store the result of multiplication    
    while (b > 0) {
        // If the least significant bit of b is set, add a to result
        if (b & 1) {
            result += a;
        }
        // Shift a left by 1 (equivalent to multiplying by 2)
        a <<= 1;
        // Shift b right by 1 (equivalent to dividing by 2)
        b >>= 1;
    }
    printf("Program: %s\n", "multiply_using_bitwise");
    printf("Result of %u * %u = %u\n", a, b, result);

    return 0;
}
