/*
 * File Name   : 06-extract_bitfield.c
 * Folder      : 01-masking
 *
 * Description :
 *  Implement 'extract_bitfield' using bitwise operators in C.
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

// 29      = 0001 1101
// Mask    = 0000 1111 (0b00001111)
// Result  = 0001 1101 & 0000 1111 = 0000 1101

int main(void)
{
    /* TODO: Implement logic here */

    uint32_t number = 0x1D; // Example input (29 in hex)
    uint32_t mask = 0x0F; // Example mask (bits 2 to 4)
    uint32_t result1 = (number & mask);
    printf("Program: %s\n", "extract_bitfield");
    printf("Number: 0x%X, Mask: 0x%X, Extracted Bitfield: 0x%X\n", number, mask, result1);

    mask = 0xF0;
    uint32_t result2 = (number & mask) >> 4; // Shift right to align the extracted bits to LSB
    printf("Program: %s\n", "extract_bitfield");
    printf("Number: 0x%X, Mask: 0x%X, Extracted Bitfield: 0x%X\n", number, mask, result2);

    uint32_t result = (result1) | (result2<<4);
    printf("Combined Extracted Bitfield: 0x%X\n", result);


    return 0;
}
