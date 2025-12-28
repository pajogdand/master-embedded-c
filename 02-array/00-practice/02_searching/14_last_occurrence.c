/*
 * File Name   : 14_last_occurrence.c
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

void last_occurrence(int arr[], int n)
{
    /* TODO: Implement logic */
    int low = 0;
    int high = n - 1;
    int mid;
    int last_index = -1;
    int find_element = 30;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == find_element)
        {
            last_index = mid;
            low = mid + 1; // Continue searching in the right half
        }
        else if (arr[mid] < find_element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (last_index != -1)
    {
        printf("Last occurrence of element found at index %d\n", last_index);
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

    last_occurrence(arr, n);
    

    return 0;
}
