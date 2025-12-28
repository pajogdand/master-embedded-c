/*
 * File Name   : 03-char_frequency.c
 * Folder      : 07-strings/01-character
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

void char_frequency(const char *str, char ch)
{
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ch) {
            count++;
        }
        i++;
    }
    printf("Frequency of character '%c': %d\n", ch, count);
}
int main(void)
{
    char_frequency("Hello World", 'l');
    char_frequency("Programming is fun", 'r');

    return 0;
}
