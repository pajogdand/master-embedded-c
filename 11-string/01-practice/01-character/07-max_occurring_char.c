/*
 * File Name   : 07-max_occurring_char.c
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

void max_occuring_char(char *str)
{
    int count[256] = {0};
    int max_count = 0;
    char max_char = '\0';

    for (int i = 0; str[i] != '\0'; i++)
    {
        count[str[i]]++;
    }

    for (int i = 0; i < 256; i++)
    {
        if (count[i] > max_count)
        {
            max_count = count[i];
            max_char = (char)i;
        }
    }

    printf("Maximum occurring character is: %c\n", max_char);
}
int main(void)
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    max_occuring_char(str);

    return 0;
}
