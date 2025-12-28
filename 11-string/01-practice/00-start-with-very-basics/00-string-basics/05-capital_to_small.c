/*
 * File Name   : 05-capital_to_small.c
 * Folder      : basic_strings
 *
 * Description :
 *  Convert a capital letter to small letter using ASCII
 *
 * Requirement :
 *  - Use loops where applicable
 *  - Do not use string library functions
 *  - Use ASCII value logic
 *  - Follow Embedded C coding standards
 *
 * Input :
 *  - Hardcoded string / character
 *
 * Output :
 *  - Printed characters / ASCII values / converted output
 *
 * Author      : Pravin Jogdand
 */

#include <stdio.h>

int main(void)
{
    /* Sample data */
    char str[] = "AbC123";
    char ch = 'A';

    /*
     * TODO:
     * Implement logic here as per requirement
     */
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            // char small_char = str[i] + 32; // Convert to small letter
            // OR
            char small_char = str[i] + ('a' - 'A'); // Convert to small letter
            // Plase note A ASCII is 65 and a ASCII is 97, difference is 32
            printf("Capital Character: %c, Small Character: %c\n", str[i], small_char);
        }

    return 0;
}
