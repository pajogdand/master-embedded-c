#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_BITS_IN_BYTE 8

void highest_turn_on_bit(unsigned long long *num , int k)
{    
    int num_of_bits = sizeof(unsigned long long) * NUM_OF_BITS_IN_BYTE;

    unsigned long long mask = 1;
        
    for(int i=num_of_bits-1;i>=0 ; i--)
    {

      if ( ( (mask<<i) & (*num) ) != 0)
      {
          printf("%d bit is set" ,i);
          break;
      }
    } 

}
int main(void)
{    
    // this in input number
    unsigned long long num = 32;
    printf("Before = %lu\n" , num);
    highest_turn_on_bit(&num , 2);
    
}
