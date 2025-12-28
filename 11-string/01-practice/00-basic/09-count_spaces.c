/*
 * File Name   : 09-count_spaces.c
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

void count_spaces(const char *str)
{
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            count++;
        }
        i++;
    }
    printf("Number of spaces: %d\n", count);
}

int main(void)
{
    printf("Program: %s\n", "count_spaces");
    count_spaces("Hello World");
    count_spaces("Programming is fun");

    return 0;
}
