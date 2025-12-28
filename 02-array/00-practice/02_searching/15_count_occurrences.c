/*
 * File Name   : 15_count_occurrences.c
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

void count_occurrences(int arr[], int n)
{
    /* TODO: Implement logic */
    int count = 0;
    int find_element = 30;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == find_element)
        {
            count++;
        }
    }
    printf("Count of element %d is %d\n", find_element, count);
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    count_occurrences(arr, n);

    return 0;
}
