/*
 * File Name   : 38_prefix_sum_array.c
 * Folder      : 06_subarray
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

void prefix_sum_array(int arr[], int n)
{
    int prefix_sum[n];
    prefix_sum[0] = arr[0];
    for(int i=1;i<n;i++)
    {
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    prefix_sum_array(arr, n);

    return 0;
}
