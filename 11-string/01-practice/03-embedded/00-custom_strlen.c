/*
 * File Name   : 00-custom_strlen.c
 * Folder      : 07-strings/03-embedded
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

int custom_strlen(const char *str)
{
const char *start = str;
    while (*str != '\0')
    {
        str++;
    }
    return str - start;
}

int main(void)
{
    char str[] = "Hello, World!";
    int length = custom_strlen(str);
    printf("Length of string: %d\n", length);

    return 0;
}
