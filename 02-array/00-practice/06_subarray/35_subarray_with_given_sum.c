/*
 * File Name   : 35_subarray_with_given_sum.c
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

void subarray_with_given_sum(int arr[], int n, int target_sum)
{
    int start = 0;
    int current_sum = 0;

    for (int end = 0; end < n; end++)
    {
        current_sum += arr[end];

        while (current_sum > target_sum && start <= end)
        {
            current_sum -= arr[start];
            start++;
        }

        if (current_sum == target_sum)
        {
            printf("Subarray found from index %d to %d\n", start, end);
            return;
        }
    }

    printf("No subarray found with given sum\n");
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    subarray_with_given_sum(arr, n , 90);

    return 0;
}
