/*
 * File Name   : 00-set_bit.c
 * Folder      : 01-masking
 *
 * Description :
 *  Implement 'set_bit' using bitwise operators in C.
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

//Example:
// To set a specific bit in a number, we can use the bitwise OR operation with a mask that has the target bit set to 1.
// For example, to set the 2nd bit (counting from 0) of the number 5 (0000 0101):
// 5      = 0000 0101
// Mask   = 0000 0100 (1 << 2)
// Result  = 0000 0101 | 0000 0100 = 0000 0101 (5, since the 2nd bit was already set)
// If we wanted to set the 1st bit instead:
// 5      = 0000 0101
// Mask   = 0000 0010 (1 << 1)
// Result  = 0000 0101 | 0000 0010 = 0000 0111 (7, with the 1st bit set)

void set_bit(uint32_t *number, unsigned int bit_position)
{
    *number |= (1U << bit_position);
}
int main(void)
{
    /* TODO: Implement logic here */

    printf("Program: %s\n", "set_bit");
    uint32_t number = 5; // Example input
    unsigned int bit_position = 1; // Example: Set the 1st bit
    printf("Original number: %u\n", number);
    set_bit(&number, bit_position);
    printf("Number after setting bit %u: %u\n", bit_position, number);

    return 0;
}
