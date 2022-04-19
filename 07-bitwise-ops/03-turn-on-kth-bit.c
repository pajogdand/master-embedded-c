#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_BITS_IN_BYTE 8

void turn_on_kth_bit(long *num , int k)
{    
    int num_of_bits = sizeof(long) * NUM_OF_BITS_IN_BYTE;
    *num = *num | (1<<k);

}
int main(void)
{    
    // this in input number
    unsigned long num = 1;
    printf("Before = %lu" , num);
    turn_on_kth_bit(&num , 2);
    printf("After = %lu" , num);
}
