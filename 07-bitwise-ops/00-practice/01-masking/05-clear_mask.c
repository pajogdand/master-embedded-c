/*
 * File Name   : 05-clear_mask.c
 * Folder      : 01-masking
 *
 * Description :
 *  Implement 'clear_mask' using bitwise operators in C.
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
// number = 21 (0001 0101)
// mask = 0x0F

int main(void)
{
    /* TODO: Implement logic here */

    printf("Program: %s\n", "set_mask");
    uint32_t number = 21; // Example input
    uint32_t mask = 0x0F; // Example mask
    number = number & (~mask); // Clear mask using bitwise AND with inverted mask
    printf("Number after clearing bits with mask 0x%X is: %u\n", mask, number);

    return 0;
}