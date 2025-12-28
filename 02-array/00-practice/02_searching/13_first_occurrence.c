/*
 * File Name   : 13_first_occurrence.c
 * Folder      : 02_searching
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

void first_occurrence(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int first_index = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == 30)
        {
            first_index = mid;
            high = mid - 1; // Continue searching in the left half
        }
        else if (arr[mid] < 30)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (first_index != -1)
    {
        printf("First occurrence of element found at index %d\n", first_index);
    }
    else
    {
        printf("Element not found\n");
    }
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    first_occurrence(arr, n);

    return 0;
}
