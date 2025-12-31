/*
 * File Name   : 08_reverse_number.c
 * Folder      : 08_loops/01_number_based
 *
 * Description :
 *   TODO: Add description
 *
 * Author      : Pravin Jogdand
 * Date        : 28-12-2025
 *
 * Interview Tags :
 *   - Loops
 */

#include <stdio.h>

void reverse_number(void)
{
    /* TODO: Implement logic */
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    int reversed_number = 0; 
    while (n != 0)
    {
        int digit = n % 10;
        reversed_number = reversed_number * 10 + digit;
        n /= 10;
    }
    printf("Reversed number is: %d\n", reversed_number);
}

int main(void)
{
    reverse_number();
    return 0;
}
