/*
 * File Name   : 02-toggle_bit.c
 * Folder      : 01-masking
 *
 * Description :
 *  Implement 'toggle_bit' using bitwise operators in C.
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
// To toggle a specific bit in a number, we can use the bitwise XOR operation with a mask that has the target bit set to 1.
// For example, to toggle the 2nd bit (counting from 0) of the number 5 (0000 0101):
// 5      = 0000 0101
// Mask   = 0000 0100 (1 << 2)
// Result  = 0000 0101 ^ 0000 0100 = 0000 0001 (1, with the 2nd bit toggled)
// If we wanted to toggle the 0th bit instead:
// 5      = 0000 0101
// Mask   = 0000 0001 (1 << 0)
// Result  = 0000 0101 ^ 0000 0001 = 0000 0100 (4, with the 0th bit toggled)

void toggle_bit(uint32_t *number, unsigned int bit_position)
{
    *number ^= (1U << bit_position);
}
int main(void)
{
    /* TODO: Implement logic here */

    printf("Program: %s\n", "toggle_bit");
    uint32_t number = 5; // Example input
    unsigned int bit_position = 0; // Example: Toggle the 0th bit
    printf("Original number: %u\n", number);
    toggle_bit(&number, bit_position);
    printf("Number after toggling bit %u: %u\n", bit_position, number);

    return 0;
}
