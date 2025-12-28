/*
 * File Name   : 04-toggle_bit_range.c
 * Folder      : 04-tricky
 *
 * Description :
 *  Implement 'toggle_bit_range' using bitwise operators in C.
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
    uint32_t number = 0x0F0F0F0F; // Example input
    uint8_t i = 8;  // Start bit position
    uint8_t j = 15; // End bit position
    uint32_t mask = ((1U << (j - i + 1)) - 1) << i; // Create mask for bits i to j
    uint32_t result = number ^ mask; // Toggle bits in the range i to j 

    printf("Program: %s\n", "toggle_bit_range");
    printf("Original Number: 0x%X\n", number);
    printf("Mask for toggling bits i to j: 0x%X\n", mask);
    printf("Result after toggling bits i to j: 0x%X\n", result);

    return 0;
}
