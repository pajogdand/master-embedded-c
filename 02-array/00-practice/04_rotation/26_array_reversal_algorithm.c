/*
 * File Name   : 26_array_reversal_algorithm.c
 * Folder      : 04_rotation
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

void array_reversal_algorithm(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while(start <= end) 
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    

    // Print reversed array
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);  
    }
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    array_reversal_algorithm(arr, n);

    return 0;
}
