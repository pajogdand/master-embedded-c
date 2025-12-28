/*
 * File Name   : 37_longest_subarray_sum_k.c
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

void longest_subarray_sum_k(int arr[], int n)
{
    int max_length = 0;
    int current_sum = 0;
    int start = 0;
    int end = 0;

    for (int i = 0; i < n; i++)
    {
        current_sum += arr[i];
        end = i;

        while (current_sum > 10 && start <= end)
        {
            current_sum -= arr[start];
            start++;
        }

        if (current_sum == 10)
        {
            int length = end - start + 1;
            if (length > max_length)
            {
                max_length = length;
            }
        }
    }

    printf("Length of longest subarray with sum %d is: %d\n", 10, max_length);
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    longest_subarray_sum_k(arr, n);

    return 0;
}
