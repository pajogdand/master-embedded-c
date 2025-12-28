/*
 * File Name   : 09-check_alphabet.c
 * Folder      : basic_strings
 *
 * Description :
 *  Check whether given character is an alphabet
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
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            printf("Character: %c is an alphabet.\n", str[i]);
        } else {
            printf("Character: %c is not an alphabet.\n", str[i]);
        }
    }
    
    return 0;
}
