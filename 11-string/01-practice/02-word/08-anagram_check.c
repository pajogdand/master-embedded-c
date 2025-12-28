/*
 * File Name   : 08-anagram_check.c
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

void check_anagram(const char *str1, const char *str2)
{
    int count1[256] = {0};
    int count2[256] = {0};
    int i;

    for (i = 0; str1[i] != '\0'; i++)
        count1[str1[i]]++;

    for (i = 0; str2[i] != '\0'; i++)
        count2[str2[i]]++;

    for (i = 0; i < 256; i++)
        if (count1[i] != count2[i])
            return;

    printf("Anagrams\n");
}

int main(void)
{
    check_anagram("listen", "silent");
    check_anagram("hello", "world");

    return 0;
}
