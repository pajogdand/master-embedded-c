/*
 * File Name   : 39_pair_with_given_sum.c
 * Folder      : 07_two_pointer
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

void pair_with_given_sum(int arr[], int n)
{
    int target_sum = 60;
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        int current_sum = arr[start] + arr[end];
        if (current_sum == target_sum)
        {
            printf("Pair found: (%d, %d)\n", arr[start], arr[end]);
            return;
        }
        else if (current_sum < target_sum)
        {
            start++;
        }
        else
        {
            end--;
        }
    }

    printf("No pair found with given sum\n");
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    pair_with_given_sum(arr, n);

    return 0;
}
