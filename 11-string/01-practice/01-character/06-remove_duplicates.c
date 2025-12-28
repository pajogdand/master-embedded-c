/*
 * File Name   : 06-remove_duplicates.c
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

void remove_duplicates(char *str)
{
    if( str == NULL || *str == '\0') {
        return; // Handle NULL or empty string
    }

    int hash[256] = {0}; // Hash table to store occurrence of characters
    int read_index = 0, write_index = 0;

    while (str[read_index] != '\0') {
        unsigned char current_char = (unsigned char)str[read_index];
        if (hash[current_char] == 0) {
            hash[current_char] = 1; // Mark character as seen
            str[write_index] = str[read_index];
            write_index++;
        }
        read_index++;
    }
    str[write_index] = '\0'; // Null-terminate the modified string
}

int main(void)
{
    char str1[] = "programming";
    char str2[] = "hello";

    remove_duplicates(str1);
    remove_duplicates(str2);

    printf("String 1 after removing duplicates: %s\n", str1);
    printf("String 2 after removing duplicates: %s\n", str2);

    return 0;
}
