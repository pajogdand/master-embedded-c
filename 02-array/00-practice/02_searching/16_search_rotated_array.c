/*
 * File Name   : 16_search_rotated_array.c
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

void search_rotated_array(int arr[], int n)
{
    /* TODO: Implement logic */
    int left = 0;
    int right = n - 1;
    int find_element = 30;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == find_element)
        {
            printf("Element found at index %d\n", mid);
            return;
        }

        // Check if the left half is sorted
        if (arr[left] <= arr[mid])
        {
            // Check if the element is in the left half
            if (find_element >= arr[left] && find_element < arr[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        // Right half must be sorted
        else
        {
            // Check if the element is in the right half
            if (find_element > arr[mid] && find_element <= arr[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    search_rotated_array(arr, n);

    return 0;
}
