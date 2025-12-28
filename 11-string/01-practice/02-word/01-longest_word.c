/*
 * File Name   : 01-longest_word.c
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

void longest_word(const char *str)
{
    int max_length = 0;
    int current_length = 0;
    int start_index = -1;
    int max_start_index = -1;

    for (int i = 0; ; i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            if (current_length == 0) {
                start_index = i; // Mark the start of a new word
            }
            current_length++;
        } else {
            if (current_length > max_length) {
                max_length = current_length;
                max_start_index = start_index;
            }
            current_length = 0; // Reset for the next word
        }

        if (str[i] == '\0') {
            break; // End of string
        }
    }

    if (max_start_index != -1) {
        printf("Longest word: ");
        for (int i = 0; i < max_length; i++) {
            putchar(str[max_start_index + i]);
        }
        printf("\nLength: %d\n", max_length);
    } else {
        printf("No words found.\n");
    }
}
int main(void)
{
    /* TODO: Implement logic here */


    return 0;
}
