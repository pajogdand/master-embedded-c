/*
 * File Name   : 02-print_ascii_only.c
 * Folder      : basic_strings
 *
 * Description :
 *  Print ASCII values of characters in string
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
        if ((unsigned char)str[i] >= 0 && (unsigned char)str[i] <= 127) {
            printf("Character: %c, ASCII: %d\n", str[i], (unsigned char)str[i]);
        }

    return 0;
}
