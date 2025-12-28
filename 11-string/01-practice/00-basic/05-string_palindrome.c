/*
 * File Name   : 05-string_palindrome.c
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

void check_palindrome(const char *str)
{
    int left = 0;
    int right = 0;
    while (str[right] != '\0') {
        right++;
    }
    right--; // Set to last character index

    while (left < right) {
        if (str[left] != str[right]) {
            printf("The string is not a palindrome.\n");
            return;
        }
        left++;
        right--;
    }
    printf("The string is a palindrome.\n");
}
int main(void)
{
    printf("Program: %s\n", "string_palindrome");
    check_palindrome("racecar");
    check_palindrome("hello");
    return 0;
}
