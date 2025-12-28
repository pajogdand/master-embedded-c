/*
 * File Name   : 04-print_small_ascii.c
 * Folder      : basic_strings
 *
 * Description :
 *  Print small letters and their ASCII values
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
        if (str[i] >= 'a' && str[i] <= 'z') {
            printf("Character: %c, ASCII: %d\n", str[i], (unsigned char)str[i]);
        }
    }

    return 0;
}
