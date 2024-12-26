#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declaration
void get_array_1(int  *arr,int *p_arr_size);

int main() {
    // Initialize random number generator
    srand(time(NULL));

    int *array_ptr;
    // Size of the array
    int arr_size = 5; // Example size, can be any positive integer

    // Call the function
    get_array_1(array_ptr ,&arr_size);

    
    // Rest of your code...
    for(size_t i=0;i<arr_size ;i++)
    {
        printf("%d ",array_ptr[i]);
    }

    return 0;
}


void get_array_1(int  *arr, int *p_arr_size)
{
    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(sizeof(int) * (*p_arr_size));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    int i=0;
    for (size_t i = 0; i < *p_arr_size; i++)
    {
        /* code */
        arr[i] = rand() % 100; // Fill the array with random numbers between 0 and 99
    }
    
    // Print the array
    for(size_t i=0;i<*p_arr_size ;i++)
    {
        printf("%d ",arr[i]);
    }
}