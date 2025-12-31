/*
 * File Name   : 34_max_subarray_sum_kadane.c
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

void max_subarray_sum_kadane(int arr[], int n)
{
    int max_sum = arr[0];
    int current_sum = arr[0];

    for(int i = 1; i < n; i++)
    {
        current_sum = (current_sum + arr[i] > arr[i]) ? (current_sum + arr[i]) : arr[i];
        max_sum = (max_sum > current_sum) ? max_sum : current_sum;
    }

    printf("Maximum subarray sum is: %d\n", max_sum);
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    max_subarray_sum_kadane(arr, n);

    return 0;
}
