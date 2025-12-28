/*
 * File Name   : 06-find_lsb.c
 * Folder      : 00-basic
 *
 * Description :
 *  Implement 'find_lsb' using bitwise operators in C.
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
// The least significant bit (LSB) of a number can be found using the bitwise AND operation with 1.
// For example:
// 5  = 0000 0101      -> LSB is 1 (5 & 1 = 1)
// 8  = 0000 1000      -> LSB is 0 (8 & 1 = 0)
// 10 = 0000 1010      -> LSB is 0 (10 & 1 = 0)
// 7  = 0000 0111      -> LSB is 1 (7 & 1 = 1)                  
int main(void)
{
    /* TODO: Implement logic here */

    printf("Program: %s\n", "find_lsb");

    int32_t number = 10; // Example input
    int32_t lsb = number & 1;
    printf("LSB of %d is %d\n", number, lsb);

    return 0;
}
