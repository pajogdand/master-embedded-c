/*
 * File Name   : 00-print_each_char.c
 * Folder      : basic_strings
 *
 * Description :
 *  Print each character of a string using loop
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
        printf("Character: %c\n", str[i]);

    return 0;
}
