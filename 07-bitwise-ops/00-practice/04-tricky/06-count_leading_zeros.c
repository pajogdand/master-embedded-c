/*
 * File Name   : 06-count_leading_zeros.c
 * Folder      : 04-tricky
 *
 * Description :
 *  Implement 'count_leading_zeros' using bitwise operators in C.
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
    unsigned int number = 0x00F00000; // Example input
    unsigned int count = 0;
    unsigned int mask = 1U << 31; // Start with the MSB
    while (mask != 0 && (number & mask) == 0) {
        count++;
        mask >>= 1; // Shift mask right to check next bit
    }
    printf("Number of leading zeros: %d\n", count);
    printf("Program: %s\n", "count_leading_zeros");

    return 0;
}
