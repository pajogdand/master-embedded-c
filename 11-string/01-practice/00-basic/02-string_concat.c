/*
 * File Name   : 02-string_concat.c
 * Folder      : 07-strings/00-basic
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

void concat_strings(char *dest, const char *src1, const char *src2)
{
    int i = 0;
    // Copy first string to destination
    while (src1[i] != '\0') {
        dest[i] = src1[i];
        i++;
    }
    // Copy second string to destination
    int j = 0;
    while (src2[j] != '\0') {
        dest[i] = src2[j];
        i++;
        j++;
    }
    dest[i] = '\0'; // Null-terminate the concatenated string
}

int main(void)
{
    /* TODO: Implement logic here */
    const char str1[] = "Hello, ";
    const char str2[] = "World!";
    char result[100]; // Ensure result is large enough to hold both strings
    concat_strings(result, str1, str2);
    printf("Concatenated string: %s\n", result);
    printf("Program: %s\n", "string_concat");
    return 0;
}
