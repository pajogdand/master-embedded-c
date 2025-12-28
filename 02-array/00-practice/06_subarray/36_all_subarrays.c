/*
 * File Name   : 36_all_subarrays.c
 * Folder      : 06_subarray
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

void all_subarrays(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            printf("[");
            for(int k=i;k<=j;k++)
            {
                printf("%d", arr[k]);
                if(k<j)
                {
                    printf(",");
                }
            }
            printf("]\n");
        }
    }
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    all_subarrays(arr, n);

    return 0;
}
