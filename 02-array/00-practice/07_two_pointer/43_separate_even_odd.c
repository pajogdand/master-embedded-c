/*
 * File Name   : 43_separate_even_odd.c
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

void separate_even_odd(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        if (arr[start] % 2 == 0)
        {
            start++;
        }
        else if (arr[end] % 2 == 1)
        {
            end--;
        }
        else
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
}

int main(void)
{
    int arr[] = {10, 21, 31, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    separate_even_odd(arr, n);

    return 0;
}
