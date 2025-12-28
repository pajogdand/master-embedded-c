// Requirments:
// Write a function to find the lowest turn on bit in a given number.
// Example: num = 18 ( 0001 0010 )
//          Output : 2 ( 0000 0010 )    

// Approach:
// 1. Create a mask with only one bit set at a time starting from LSB
// 2. AND the mask with the given number   

// 0001 0010
// 0000 0001
// ---------
// 0000 0000  ==> not set

// 0001 0010
// 0000 0010
// ---------
// 0000 0010  ==> set , so 2nd bit is lowest turn on bit
//
// for : i =0 ; i++ ; i<8
#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_BITS_IN_BYTE 8

int lowest_turn_on_bit(unsigned char *num , int k)
{    
    int num_of_bits = sizeof(unsigned char) * NUM_OF_BITS_IN_BYTE;

    char mask = 1;
    int i=0;
    for(;i<num_of_bits ; i++)
    {

      if ( ( (mask<<i) & (*num) ) != 0)
      {
          break;
      }
    }
    
    return i;
}
int main(void)
{    
    // this in input number
    char num = 4;
    printf("Input value = %u\n" , num);
    printf("lowest turn on bit is %d\n",lowest_turn_on_bit(&num , 2));
    
    return (0);
}
