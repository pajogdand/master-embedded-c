/*
 * File Name   : 07-string_to_lowercase.c
 * Folder      : basic_strings
 *
 * Description :
 *  Convert entire string to lowercase
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
            char lower_char = str[i] + ('a' - 'A'); // Convert to lowercase
            printf("Original Character: %c, Lowercase Character: %c\n", str[i], lower_char);
        }
    return 0;
}
