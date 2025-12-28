/*
 * File Name   : 25_right_rotate_by_k.c
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

void right_rotate_by_k(int arr[], int n, int k)
    
{
    if(n == 0 || k <= 0 || k >= n)
    {
        return;
    }

    int temp[] = {0};
    for(int i=0;i<k;i++)
    {
        temp[i] = arr[i];
    }

    for(int i=n-1;i>=k;i--)
    {
        arr[i] = arr[i-k];
    }

    for(int i=0;i<k;i++)
    {
        arr[n-k+i] = temp[i];
    }
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    right_rotate_by_k(arr, n, 2);

    return 0;
}
