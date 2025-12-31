/*
 * File Name   : 03_sum_of_n_numbers.c
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

void sum_of_n_numbers(void)
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    printf("Sum of first %d numbers is: %d\n", n, sum);
}

int main(void)
{
    sum_of_n_numbers();
    return 0;
}
