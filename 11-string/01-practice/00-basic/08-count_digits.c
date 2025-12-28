/*
 * File Name   : 08-count_digits.c
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

void count_digits(const char *str)
{
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        char ch = str[i];
        if (ch >= '0' && ch <= '9') {
            count++;
        }
        i++;
    }
    printf("Number of digits: %d\n", count);
}
int main(void)
{
    printf("Program: %s\n", "count_digits");
    count_digits("Hello123World");
    count_digits("Programming2023");

    return 0;
}
