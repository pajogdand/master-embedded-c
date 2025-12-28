/*
 * File Name   : 03-reverse_words.c
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


void reverse_word(int left, int right, char *str)
{
    while (left < right)
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

void reverse_each_word(char *str)
{
    int start = 0;
    int i = 0;

    for (i = 0; ; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            reverse_word(start, i - 1, str);
            start = i + 1;
        }

        if (str[i] == '\0')
            break;
    }
}

int main(void)
{
    char str[] = "This is a test string";

    reverse_each_word(str);
    printf("Reversed words: %s\n", str);
    return 0;
}
