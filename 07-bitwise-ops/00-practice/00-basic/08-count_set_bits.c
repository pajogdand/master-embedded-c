/*
 * File Name   : 08-count_set_bits.c
 * Folder      : 00-basic
 *
 * Description :
 *  Implement 'count_set_bits' using bitwise operators in C.
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

// Example :
// For example, in an 8-bit representation:
// 13 = 0000 1101 -> Number of set bits = 3
int main(void)
{
    /* TODO: Implement logic here */

    printf("Program: %s\n", "count_set_bits");
    uint32_t number = 13; // Example input
    unsigned int count = 0;
    for (int i = 0; i < 32; i++)
    {
        count += (number>>i) & 1; // Increment count if LSB is 1
    }
    printf("Number of set bits in %u is %u\n", number, count);
    return 0;
}
