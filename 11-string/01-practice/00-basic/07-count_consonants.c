/*
 * File Name   : 07-count_consonants.c
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

void count_consonants(const char *str)
{
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        char ch = str[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            if (!(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
                  ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
                count++;
            }
        }
        i++;
    }
    printf("Number of consonants: %d\n", count);
}
int main(void)
{
    count_consonants("Hello World");
    count_consonants("Programming");

    return 0;
}
