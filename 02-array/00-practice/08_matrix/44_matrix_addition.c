/*
 * File Name   : 44_matrix_addition.c
 * Folder      : 08_matrix
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

void matrix_addition(int arr[], int n)
{
    /* TODO: Implement logic */
    int matrix_size = (int)(n / 2); // Assuming square matrices of size sqrt(n/2) x sqrt(n/2)
    int result[matrix_size][matrix_size]; 
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            result[i][j] = arr[i * matrix_size + j] + arr[(i + matrix_size) * matrix_size + j];
        }
    }
}

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    matrix_addition(arr, n);

    return 0;
}
