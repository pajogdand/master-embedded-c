/*
 * File Name   : 08-min_occurring_char.c
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

void min_occuring_char(char *str)
{
    int count[256] = {0};
    int min_count = 1000;
    char min_char = '\0';

    for (int i = 0; str[i] != '\0'; i++)
    {
        count[str[i]]++;
    }

    for (int i = 0; i < 256; i++)
    {
        if (count[i] > 0 && count[i] < min_count)
        {
            min_count = count[i];
            min_char = (char)i;
        }
    }

    printf("Minimum occurring character is: %c\n", min_char);
}

int main(void)
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    min_occuring_char(str);

    return 0;
}
