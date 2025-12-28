/*
 * File Name   : 41_container_with_most_water.c
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

void container_with_most_water(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    int max_area = 0;

    while (start < end)
    {
        int width = end - start;
        int height = (arr[start] < arr[end]) ? arr[start] : arr[end];
        int area = width * height;

        if (area > max_area)
        {
            max_area = area;
        }

        if (arr[start] < arr[end])
        {
            start++;
        }
        else
        {
            end--;
        }
    }

    printf("Maximum area: %d\n", max_area);
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    container_with_most_water(arr, n);

    return 0;
}
