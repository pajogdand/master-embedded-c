/*
 * File Name   : 32_most_frequent_element.c
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

void most_frequent_element(int arr[], int n)
{
    /* TODO: Implement logic */
    int max_count = 0;
    int most_frequent_element = arr[0];
    for(int i=0;i<n;i++)
    {
        int count = 0;
        for(int j=0;j<n;j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }
        if(count > max_count)
        {
            max_count = count;
            most_frequent_element = arr[i];
        }
    }
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    most_frequent_element(arr, n);

    return 0;
}
