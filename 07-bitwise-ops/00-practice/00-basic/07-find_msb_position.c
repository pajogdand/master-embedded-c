/*
 * File Name   : 07-find_msb_position.c
 * Folder      : 00-basic
 *
 * Description :
 *  Implement 'find_msb_position' using bitwise operators in C.
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
// The most significant bit (MSB) position of a number can be found by checking each               
// bit from the highest to the lowest until we find a bit that is set to 1.
// For example, in an 8-bit representation:
// 18 = 0001 0010 -> MSB is at position 4 (counting from 0)
// 5  = 0000 0101 -> MSB is at position 2
// 8  = 0000 1000 -> MSB is   at position 3 

int main(void)
{
    /* TODO: Implement logic here */

    printf("Program: %s\n", "find_msb_position");

    uint32_t number = 18; // Example input
    int msb_position = -1; // Initialize to -1 to indicate no bits are set
    for (int i = 31; i >= 0; i--)
    {
        if (number & (1U << i))
        {
            msb_position = i;
            break;
        }
    }
    printf("MSB position of %u is %d\n", number, msb_position);
    return 0;
}
