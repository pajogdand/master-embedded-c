/*
 * File Name   : 10-convert-upper-case.c
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

void covert_to_upper_case(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
        i++;
    }
}

void convert_to_upper_case_using_pointer(char *str)
{
    char *ptr = str;
    while (*ptr != '\0') {
        if (*ptr >= 'a' && *ptr <= 'z') {
            *ptr = *ptr - ('a' - 'A');
        }
        ptr++;
    }
}

void convert_to_upper_case_using_bitwise(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            // str[i] = str[i] & 0xDF; // Clear the 6th bit to convert to uppercase
            str[i] = str[i] & (~(1 << 5)); // Alternatively, subtract 32 to convert to uppercase
        }
        i++;
    }
}

int main(void)
{
    printf("Program: %s\n", "convert_to_upper_case");
    char str1[] = "hello world";
    covert_to_upper_case(str1);
    printf("Converted string: %s\n", str1);
    char str2[] = "programming is fun";
    covert_to_upper_case(str2);
    printf("Converted string: %s\n", str2);
    char str3[] = "embedded c";
    convert_to_upper_case_using_pointer(str3);
    printf("Converted string using pointer: %s\n", str3);
    char str4[] = "bitwise operation";
    convert_to_upper_case_using_bitwise(str4);
    printf("Converted string using bitwise: %s\n", str4);
    return 0;
}
