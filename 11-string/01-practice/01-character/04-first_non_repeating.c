/*
 * File Name   : 04-first_non_repeating.c
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

void first_non_repeating_character(const char *str)
{
    if (str == NULL || *str == '\0') {
        printf("Input string is NULL or empty.\n");
        return;
    }
    
    int freq[256] = {0}; // Frequency array for all ASCII characters
    int i = 0;
    
    // First pass: Count frequency of each character
    while (str[i] != '\0') {
        freq[(unsigned char)str[i]]++;
        i++;
    }

    // Second pass: Find the first non-repeating character
    i = 0;
    while (str[i] != '\0') {
        if (freq[(unsigned char)str[i]] == 1) {
            printf("First non-repeating character: %c\n", str[i]);
            return;
        }
        i++;
    }

    printf("No non-repeating character found.\n");
}

int main(void)
{
    first_non_repeating_character("hellho");
    first_non_repeating_character("programmingp");

    return 0;
}
