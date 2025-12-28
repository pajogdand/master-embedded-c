/*
 * File Name   : 03-check_bit.c
 * Folder      : 01-masking
 *
 * Description :
 *  Implement 'check_bit' using bitwise operators in C.
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
// To check if a specific bit in a number is set (1) or clear (0), we can use the bitwise AND operation with a mask that has the target bit set to 1.
// For example, to check the 2nd bit (counting from 0) of the number 5 (0000 0101):
// 5      = 0000 0101
// Mask   = 0000 0100 (1 << 2)
// Result  = 0000 0101 & 0000 0100 =    0000 0100 (non-zero, so the 2nd bit is set)
// If we wanted to check the 1st bit instead:
// 5      = 0000 0101
// Mask   = 0000 0010 (1 << 1)
// Result  = 0000 0101 & 0000 0010 =    0000 0000 (zero, so the 1st bit is clear)

void check_bit(uint32_t number, unsigned int bit_position)
{
    if (number & (1U << bit_position))
    {
        printf("Bit %u is SET\n", bit_position);
    }
    else
    {
        printf("Bit %u is CLEAR\n", bit_position);
    }
}

int main(void)
{
    /* TODO: Implement logic here */

    printf("Program: %s\n", "check_bit");

    uint32_t number = 5; // Example input
    unsigned int bit_position = 2; // Example: Check the 2nd bit
    printf("Number: %u\n", number);
    check_bit(number, bit_position);

    return 0;
}
