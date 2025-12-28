/*
 * File Name   : 01-clear_bit.c
 * Folder      : 01-masking
 *
 * Description :
 *  Implement 'clear_bit' using bitwise operators in C.
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
// To clear a specific bit in a number, we can use the bitwise AND operation with      a mask that has the target bit set to 0 and all other bits set to 1.
// For example, to clear the 2nd bit (counting from 0) of the number 7 (0000 0111):
// 7      = 0000   0111
// Mask   = 1111  1011 ~(1 << 2)
// Result  = 0000  0111 & 1111  1011 = 0000  0011 (3, with the 2nd bit cleared)
// If we wanted to clear the 1st bit instead:
// 7      = 0000  0111
// Mask   = 1111  1101 ~(1 << 1)
// Result  = 0000  0111 & 1111  1101 = 0000  0101 (5, with the 1st bit cleared)

void clear_bit(uint32_t *number, unsigned int bit_position)
{
    *number &= ~(1U << bit_position);
}

int main(void)
{
    /* TODO: Implement logic here */

    printf("Program: %s\n", "clear_bit");

    return 0;
}
