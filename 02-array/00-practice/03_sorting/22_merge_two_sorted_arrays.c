/*
 * File Name   : 22_merge_two_sorted_arrays.c
 * Folder      : 03_sorting
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

void merge_two_sorted_arrays(int arr1[], int arr2[], int n1, int n2)
{
    /* TODO: Implement logic */
    int n;
    if(n1 > n2) n = n1;
    else n = n2;
     
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            if(arr1[i] < arr2[j])
            {
                printf("%d ",arr1[i]);
            }
            else
            {
                printf("%d ",arr2[j]);
            }
        }
    }
}

int main(void)
{
    int arr1[] = {10, 20, 30, 40, 50};
    int arr2[] = {15, 25, 35, 45, 55};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    merge_two_sorted_arrays(arr1,arr2, n1, n2);

    return 0;
}
