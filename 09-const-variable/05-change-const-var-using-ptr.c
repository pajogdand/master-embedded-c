#include <stdio.h>
#include <stdlib.h>

const int gol_n = 10;

int main(void)
{
    const int loc_n = 500;
    //n = 1000; This is not allowed

    int *ptr;
    ptr = &loc_n;

    printf("before loc_n = %d\n" , loc_n);
    *ptr = 1000;
    // This is allowed since type of ptr is not const hence read write in possible
    // This will give just warning and not error
    printf("after loc_n = %d\n" , loc_n);
    
    int *ptr1;
    ptr1 = &gol_n;
    
    printf("before gol_n = %d\n" , gol_n);
    // *ptr1 = 100;
    // This is not allowed
    // This will give error
    printf("after gol_n = %d\n" , gol_n);

    exit(0);
}
