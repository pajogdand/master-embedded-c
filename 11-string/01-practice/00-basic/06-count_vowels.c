/*
 * File Name   : 06-count_vowels.c
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

void count_vowels(const char *str)
{
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        char ch = str[i];
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
            ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
        i++;
    }
    printf("Number of vowels: %d\n", count);
}
int main(void)
{
    printf("Program: %s\n", "count_vowels");
    count_vowels("Hello World");
    count_vowels("Programming");

    return 0;
}
