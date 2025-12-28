/*
 * File Name   : 24_left_rotate_by_k.c
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

void left_rotate_by_k(int arr[], int n, int sift_by_k)
{
    if(n == 0 || sift_by_k <= 0 || sift_by_k >= n)
    {
        return;
    }
    
    /* TODO: Implement logic */
    int temp[] = {0};
    for(int i=0;i<sift_by_k;i++)
    {
        temp[i] = arr[i];
    }

    for(int i=0;i<sift_by_k;i++)
    {
        arr[i] = arr[i+sift_by_k];
    }

    for(int i=0;i<sift_by_k;i++)
    {
        arr[n-sift_by_k+i] = temp[i];
    }
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    left_rotate_by_k(arr, n, 2);

    return 0;
}
