/*
 * File Name   : 06_table_of_number.c
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

void table_of_number(void)
{
    /* TODO: Implement logic */
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Table of %d is:\n", n);
    for (int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}

int main(void)
{
    table_of_number();
    return 0;
}
