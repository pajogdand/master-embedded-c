/*
 * File Name   : 42_move_zeroes_to_end.c
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

void move_zeroes_to_end(int arr[], int n)
{
    /* TODO: Implement logic */
    int count = 0; // Count of non-zero elements
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[count++] = arr[i]; // Move non-zero element to the front
        }
    }

    // Fill remaining positions with zeroes
    while (count < n)
    {
        arr[count++] = 0;
    }
    // Print modified array
    printf("Array after moving zeroes to end: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(void)
{
    int arr[] = {10, 0, 0, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    move_zeroes_to_end(arr, n);

    return 0;
}
