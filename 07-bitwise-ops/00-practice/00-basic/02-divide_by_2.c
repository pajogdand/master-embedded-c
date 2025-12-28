/*
 * File Name   : 02-divide_by_2.c
 * Folder      : 00-basic
 *
 * Description :
 *  Implement 'divide_by_2' using bitwise operators in C.
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


// 3      = 0000 0011
// 3 >> 1 = 0000 0001 = 1

// 4      = 0000 0100
//4 >> 1  = 0000 0010 = 2

#include <stdio.h>
#include <stdint.h>


int main(void)
{
    /* TODO: Implement logic here */

    printf("Program: %s\n", "divide_by_2");
    unsigned int number = 5; // Example input
    unsigned int result = number >> 1;  // Divide by 2 using right shift 

    return 0;
}
