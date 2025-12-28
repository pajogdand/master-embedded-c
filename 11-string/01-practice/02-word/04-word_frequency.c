/*
 * File Name   : 04-word_frequency.c
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

void word_frequency(const char *str)
{
    int freq[100] = {0};
    int i = 0;
    int j = 0;
    int k = 0;
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++)
        len++;

    for (int i = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            for (int j = i; str[j] != ' ' && str[j] != '\0'; j++)
            {
                freq[k]++;
            }
            k++;
        }
    }

    for (int i = 0; i < k; i++)
    {
        printf("Frequency of word %d: %d\n", i + 1, freq[i]);
    }
}

int main(void)
{
    char str[] = "This is a test string";

    word_frequency(str);

    return 0;
}
