/*
 * File Name   : 02_sum_of_elements.c
 * Folder      : 01_basic
 *
 * Description :
 *   TODO: Add description
 *
 * Author      : Pravin Jogdand
 * Date        : 26-12-2025
 *
 * Interview Tags :
 *   - Arrays
 */

#include <stdio.h>

void sum_of_elements(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        sum += arr[i];
    }
    printf("Sum of elements: %d\n", sum);
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    sum_of_elements(arr, n);

    return 0;
}
