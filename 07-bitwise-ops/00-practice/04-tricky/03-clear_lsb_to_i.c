/*
 * File Name   : 03-clear_lsb_to_i.c
 * Folder      : 04-tricky
 *
 * Description :
 *  Implement 'clear_lsb_to_i' using bitwise operators in C.
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
    printf("Program: %s\n", "clear_lsb_to_i");
    unsigned int number = 0xFFABCD12; // Example input
    unsigned int i = 12; // Clear LSB to bit position 12
    unsigned int mask = ~((1U << i) - 1); // Create mask to clear bits 0 to i-1
    unsigned int result = number & mask;  

    printf("Original Number: 0x%X\n", number);
    printf("Mask to clear LSB to i: 0x%X\n", mask);
    printf("Result after clearing LSB to i: 0x%X\n", result );
    return 0;
}
