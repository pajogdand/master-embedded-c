#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_BITS_IN_BYTE 8

void turn_off_kth_bit(long *num , int k)
{    
    
    *num = *num & ( ~(1<<k) );

}
int main(void)
{    
    // this in input number
    unsigned long num = 7;
    printf("Before = %lu" , num);
    turn_off_kth_bit(&num , 2);
    printf("After = %lu" , num);
}
