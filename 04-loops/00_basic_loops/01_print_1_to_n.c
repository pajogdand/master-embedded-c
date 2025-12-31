/*
 * File Name   : 01_print_1_to_n.c
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

void print_1_to_n(void)
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}

int main(void)
{
    print_1_to_n();
    return 0;
}
