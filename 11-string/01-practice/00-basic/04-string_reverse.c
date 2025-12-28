/*
 * File Name   : 04-string_reverse.c
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

void reverse_string(const char *src, char *dest)
{
    int len = 0;
    while (src[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len; i++) {
        dest[i] = src[len - 1 - i];
    }
    dest[len] = '\0'; // Null-terminate the reversed string
}

void inplace_reverse_string(char *str)
{
    int start = 0;
    int end = 0;
    while (str[end] != '\0') {
        end++;
    }
    end--; // Set to last character index

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void inplace_reverse_string_using_pointer(char *str)
{
    char *start = str;
    char *end = str;
    while (*end != '\0') {
        end++;
    }
    end--; // Set to last character

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}



int main(void)
{
    printf("Program: %s\n", "string_reverse");
    char src[] = "Hello";
    char dest[100];
    reverse_string(src, dest);
    printf("Reversed string: %s\n", dest);
    inplace_reverse_string(src);
    printf("In-place reversed string: %s\n", src);

    char src2[] = "World";
    inplace_reverse_string_using_pointer(src2);
    printf("In-place reversed string using pointer: %s\n", src2);
    
    return 0;
}
