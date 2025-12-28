/*
 * File Name   : 05_second_largest.c
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

void second_largest(int arr[], int n)
{
    int max = arr[0];
    int second_max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            second_max = max;
            max = arr[i];
        }
        else if (arr[i] > second_max && arr[i] != max)
        {
            second_max = arr[i];
        }
    }
    printf("Second largest element: %d\n", second_max);
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    second_largest(arr, n);

    return 0;
}
