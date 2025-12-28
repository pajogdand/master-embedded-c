// Requirement: Write a function to turn off kth bit of a number
// Example: num = 7(0000 0111) , k = 2
//          Output : 3  ( 0000 0011 )


// 0000 0111

// 0000 0001
// 0000 0100  (1<<k)
// 1111 1011  (~(1<<k)) MASK

// INPUT ==> 0000 0111
// MASK  ==> 1111 1011
// -----------------------
// OUTPUT ==> 0000 0011

// // 0000 0011













#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_BITS_IN_BYTE 8

void turn_off_kth_bit(char *num , int k)
{    
    // char mask = ~(1<<k);
    // *num = *num & mask;
    *num = *num & ( ~(1<<k) );

}
int main(void)
{    
    // this in input number
    unsigned char num = 7;
    printf("Before = %u \n" , num);
    turn_off_kth_bit(&num , 2);
    printf("After = %u \n" , num);
}
