#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    int A[]= {1,5,3,0};
    int size = 4;
    int largetest = INT_MIN;
    int sec_largetest = INT_MIN;

    for(int i= 0;i<size ; i++)
    {
        if(A[i] > largetest)
        {
            sec_largetest = largetest;
            largetest = A[i];
        }
        else if(A[i] > sec_largetest)
        {
            sec_largetest = A[i];
        }
    }

    printf("largest = %d , sec_largest = %d \n" , largetest , sec_largetest);
    exit(0);
}