/*
 * File Name   : 05_odd_numbers.c
 * Folder      : 08_loops/00_basic_loops
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

void odd_numbers(void)
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Odd numbers up to %d are: ", n);
    for (int i = 1; i <= n; i += 2)
    {
        printf("%d ", i);
    }
    printf("\n");
}

int main(void)
{
    odd_numbers();
    return 0;
}
