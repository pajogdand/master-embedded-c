/*
 * File Name   : 02-shortest_word.c
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


void shortest_word(const char *str)
{
    int min_length = -1;
    int current_length = 0;
    int start_index = -1;
    int min_start_index = -1;

    for (int i = 0; ; i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            if (current_length == 0) {
                start_index = i; // Mark the start of a new word
            }
            current_length++;
        } else {
            if (current_length > 0 && (min_length == -1 || current_length < min_length)) {
                min_length = current_length;
                min_start_index = start_index;
            }
            current_length = 0; // Reset for the next word
        }

        if (str[i] == '\0') {
            break; // End of string
        }
    }

    if (min_start_index != -1) {
        printf("Shortest word: ");
        for (int i = 0; i < min_length; i++) {
            putchar(str[min_start_index + i]);
        }
        printf("\nLength: %d\n", min_length);
    } else {
        printf("No words found.\n");
    }
}
int main(void)
{
    char str[] = "This is a test string";

    shortest_word(str);

    return 0;
}
