#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b,c;
    
    // arr is poiner to int of 3
    int *arr[3] = {&a , &b , &c};

    // p is ponter of array of pointer of 3
    int *(*p)[3] = &arr;

    for(int i=0;i<3;i++)
    {
        *(*p)[i] = i;
    }

    for(int i=0;i<3;i++)
    {
        printf( "%d \t" , *(*p)[i]);
    }
    exit(0);    
}