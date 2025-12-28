/*
 * File Name   : 04-check_positive_negative.c
 * Folder      : 00-basic
 *
 * Description :
 *  Implement 'check_positive_negative' using bitwise operators in C.
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
// For a signed integer, the most significant bit (MSB) indicates the sign.
// If MSB is 0, the number is positive.
// If MSB is 1, the number is negative
// For example, in an 8-bit representation:
//  5  = 0000 0101 (positive)
// -5  = 1111 1011 (negative)
int main(void)
{
    /* TODO: Implement logic here */

    printf("Program: %s\n", "check_positive_negative");
    int32_t number = -10; // Example input
    if (number & (1 << 31)) {
        printf("The number %d is Negative\n", number);
    } else {
        printf("The number %d is Positive\n", number);
    }

    return 0;
}
