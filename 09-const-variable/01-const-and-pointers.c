#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 10;
    const int *p = &n;
    
    p = &n;

    n  = 11;
    // value of n can be modified since its data type is just int and not const int

    // *p = 100; This will not work since type of p is not int* and its is const int *

    int m = 10;
    p = &m;
    // This is allowed since here const is [int *] 

     

    exit(0);
}