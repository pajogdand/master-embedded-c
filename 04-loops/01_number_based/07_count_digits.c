/*
 * File Name   : 07_count_digits.c
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

void count_digits(void)
{
    /* TODO: Implement logic */
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    if(n==0)
    {
        printf("Number of digits in 0 is 1\n");
        return;
    }
    int count = 0;
    int temp = n;
    while (temp != 0)
    {
        temp /= 10;
        count++;
    }
    printf("Number of digits in %d is %d\n", n, count);
}

int main(void)
{
    count_digits();
    return 0;
}
