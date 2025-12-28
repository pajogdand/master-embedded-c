/*
 * File Name   : 00-even_odd.c
 * Folder      : 00-basic
 *
 * Description :
 *  Implement 'even_odd' using bitwise operators in C.
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

// 0 = 0000000 0
// 1 = 0000000 1
// 2 = 0000001 0
// 3 = 0000001 1
// 4 = 0000010 0
// 5 = 0000010 1
// 6 = 0000011 0
// 7 = 0000011 1
int main(void)
{
    /* TODO: Implement logic here */
    unsigned int number = 4; // Example input

    if (number & 1)
    {
        printf("%u is Odd\n", number);
    }
    else
    {
        printf("%u is Even\n", number);
    }

    printf("Program: %s\n", "even_odd");

    return 0;
}
