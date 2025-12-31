/*
 * File Name   : 31_remove_duplicates_unsorted.c
 * Folder      : 05_frequency
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
    
void remove_duplicates_unsorted(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                for(int k = j; k < n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                n--;
                j--;
            }
        }
    }

    printf("Array after removing duplicates: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    remove_duplicates_unsorted(arr, n);

    return 0;
}
