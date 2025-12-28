/*
 * File Name   : 30_remove_duplicates_sorted.c
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

void remove_duplicates_sorted(int arr[], int n)
{
    int i = 0;
    int j = 1;
    while(j < n)
    {
        if(arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
        j++;
    }
    printf("Array after removing duplicates: ");
    for(int k = 0; k <= i; k++)
    {
        printf("%d ", arr[k]); 
    }
}

int main(void)
{
    int arr[] = {10, 10, 10 ,20, 30, 30 , 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    remove_duplicates_sorted(arr, n);

    return 0;
}
