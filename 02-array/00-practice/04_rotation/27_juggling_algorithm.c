/*
 * File Name   : 27_juggling_algorithm.c
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

void juggling_algorithm(int arr[], int n)
{
    int gcd = 1;
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            gcd = i;
        }
    }

    for(int i = 0; i < gcd; i++)
    {
        int temp = arr[i];
        int j = i;
        while(1)
        {
            int k = (j + n) % n;
            if(k == i)
            {
                break;
            }
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    juggling_algorithm(arr, n);

    return 0;
}
