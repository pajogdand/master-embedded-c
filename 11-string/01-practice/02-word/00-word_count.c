/*
 * File Name   : 00-word_count.c
 * Folder      : 07-strings/02-word
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

#include <stdio.h>

void print_word_lengths(const char *str)
{
    int len = 0;
    int in_word = 0;

    for (int i = 0; ; i++)
    {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\0')
        {
            in_word = 1;
            len++;
        }
        else
        {
            if (in_word)
            {
                printf("Word length: %d\n", len);
                len = 0;
                in_word = 0;
            }

            if (str[i] == '\0')
                break;
        }
    }
}

int main(void)
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    print_word_lengths(str);

    return 0;
}
