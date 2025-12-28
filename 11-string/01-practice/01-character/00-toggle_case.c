/*
 * File Name   : 00-toggle_case.c
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

void toggle_case(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A'); // Convert to uppercase
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A'); // Convert to lowercase
        }
        i++;
    }
}

int main(void)
{
    char str1[] = "Hello World";
    toggle_case(str1);
    printf("Toggled string: %s\n", str1);

    char str2[] = "Programming is Fun";
    toggle_case(str2);
    printf("Toggled string: %s\n", str2);

    return 0;
}
