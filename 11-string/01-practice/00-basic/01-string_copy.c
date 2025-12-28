/*
 * File Name   : 01-string_copy.c
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

void copy_string(char *dest, const char *src)
{   
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
int main(void)
{
    /* TODO: Implement logic here */

    const char source[] = "Hello, World!";
    char destination[50]; // Ensure destination is large enough     
    copy_string(destination, source);
    printf("Copied string: %s\n", destination);
    printf("Program: %s\n", "string_copy");
    return 0;
}
