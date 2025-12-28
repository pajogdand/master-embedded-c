#include <stdio.h>
//Bsic Array Example in C
int main()
{
    int a ; int b ; int c ;int d ; int e;
    // Declare an array of integers
    int numbers[5];

    // Initialize the array
    numbers[0] = 10; // 0
    numbers[1] = 20; // 1
    numbers[2] = 30; // 2
    numbers[3] = 40; // 3
    numbers[4] = 50; // 4

    // Access and print array elements
    printf("Array elements are:\n");
    for(int i = 0; i < 5; i++) {
        printf("Element at index %d: %d\n", i, numbers[i]);
    }

    // Modify an array element
    numbers[2] = 100;
    printf("\nAfter modifying, element at index 2: %d\n", numbers[2]);

    return 0;
}