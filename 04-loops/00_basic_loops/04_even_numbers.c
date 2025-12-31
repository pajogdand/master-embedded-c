/*
 * File Name   : 04_even_numbers.c
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

void even_numbers(void)
{
    /* TODO: Implement logic */
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Even numbers up to %d are: ", n);
    for (int i = 2; i <= n; i += 2)
    {
        printf("%d ", i);
    }
    printf("\n");
}

int main(void)
{
    even_numbers();
    return 0;
}
