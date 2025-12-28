/*
 * File Name   : 02-clear_msb_to_i.c
 * Folder      : 04-tricky
 *
 * Description :
 *  Implement 'clear_msb_to_i' using bitwise operators in C.
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

    uint32_t number = 0xFFABCD12; // Example input
    uint8_t i = 12; // Clear MSB to bit position 12
    uint32_t mask = (1U << i) - 1; // Create mask to keep bits 0 to i-1
    uint32_t result = number & mask;
    printf("Original Number: 0x%X\n", number);
    printf("Mask to clear MSB to i: 0x%X\n", mask);
    printf("Result after clearing MSB to i: 0x%X\n", result);
    printf("Program: %s\n", "clear_msb_to_i");

    return 0;
}
