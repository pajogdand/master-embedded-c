/*
 * File Name   : 23_left_rotate_by_one.c
 * Folder      : 04_rotation
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

void left_rotate_by_one(int arr[], int n)
{
    /* TODO: Implement logic */
    int temp = arr[0];
    for(int i=0;i<n-1;i++)
    {
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    left_rotate_by_one(arr, n);

    return 0;
}
