/*
 * File Name   : 02_print_n_to_1.c
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

void print_n_to_1(void)
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = n; i >= 1; i--)
    {
        printf("%d ", i);
    }
    printf("\n");
}
    
int main(void)
{
    print_n_to_1();
    return 0;
}
