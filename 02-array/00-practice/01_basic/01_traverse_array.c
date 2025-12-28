/*
 * File Name   : 01_traverse_array.c
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

void traverse_array(int arr[], int n)
{
    /* TODO: Implement logic */
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    traverse_array(arr, n);

    return 0;
}
