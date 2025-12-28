/*
 * File Name   : 00-string_length.c
 * Folder      : 07-strings/00-basic
 *
 * Description :
 *  TODO: Describe the problem statement.
 *
 * Input :
 *  TODO: Define input.
 *
 * Output :
 *  TODO: Define expected output.
 *
 * Requirements :
 *  - Use standard C
 *  - Avoid library functions unless specified
 *  - Follow Embedded C coding standards
 *
 * Author      : Pravin Jogdand
 */

#include <stdio.h>

void calculate_string_length(void)
{
    /* TODO: Implement logic here */
    const char str[] = "Hello, World!";
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    printf("Length of the string: %d\n", length);
}

int main(void)
{
    printf("Program: %s\n", "string_length");

    calculate_string_length();

    return 0;
}
