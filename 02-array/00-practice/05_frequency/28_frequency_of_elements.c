/*
 * File Name   : 28_frequency_of_elements.c
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

void frequency_of_elements(int arr[], int n, int frequency_of_element)
{
    int count = 0;
    int is_present = 0;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i] == frequency_of_element)
        {
            count++;
            is_present = 1;
        }
    }

    if(is_present == 1)
    {
        return;
    }
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    frequency_of_elements(arr, n,20);

    return 0;
}
