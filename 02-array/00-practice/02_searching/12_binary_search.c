/*
 * File Name   : 12_binary_search.c
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

void binary_search(int arr[], int n)
{
    /* TODO: Implement logic */
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == 30)
        {
            printf("Element found at index %d\n", mid);
            return;
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
    printf("Element not found\n");
}

void binary_search_using_left_and_right(int arr[], int n)
{
        int left = 0;
        int right = n - 1;
        
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == 30)
            {
                printf("Element found at index %d\n", mid);
                return;
            }
            else if (arr[mid] < 30)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    binary_search(arr, n);
    
    return 0;
}
