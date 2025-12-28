/*
 * File Name   : 05-count_trailing_zeros.c
 * Folder      : 04-tricky
 *
 * Description :
 *  Implement 'count_trailing_zeros' using bitwise operators in C.
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
    uint32_t number = 0x0012C000; // Example input
    uint8_t count = 0;
    while ((number & 1) == 0 && count < 32) {
        count++;
        number >>= 1;
    }
    printf("Program: %s\n", "count_trailing_zeros");
    printf("Number of trailing zeros: %d\n", count);

    return 0;
}
