// Requirement: Write a function to  bit of a number
// Example: num = 1(0000 0001) , k = 2
//          Output : 3  ( 0000 0101 )

// write name to function : turn_on_kth_bit , num , k
// turn on the kth ?
// go to that bit and AND with orginal number
// 


#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_BITS_IN_BYTE 8

void turn_on_kth_bit(unsigned char *num , int k)
{    
    int num_of_bits = sizeof(char) * NUM_OF_BITS_IN_BYTE;
    *num = *num | (1<<k);

}
int main(void)
{    
    // this in input number
    char num = 1;
    printf("Before = %u \n" , num);
    turn_on_kth_bit(&num , 2);
    printf("After = %u \n" , num);
}
