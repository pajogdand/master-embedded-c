#include <stdio.h>
#include <stdlib.h>

/*Take two integers n1 and n2,
 and swap the bits index wise 
meaning that bit 1 of n1 should be 
reflected in bit 1 of n2 and vice versa*/

void swap_bits_of_two_nums(unsigned int *num1 , unsigned int *num2)
{
    unsigned int temp1 = 0;
    unsigned int temp2 = 0;
    for(int i=0 ; i<32; i++)
    {
        if( ((*num1) & (1<<i) ) )
        {
            temp2 = temp2 | (1 << i);
        }
        if( ((*num2) & (1<<i) ) )
        {
            temp1 = temp1 | (1 << i);
        }
    }
     
     (*num1) = temp1;
     (*num2) = temp2;
}

int main(void)
{
    unsigned int num1 = 1;
    unsigned int num2 = 2;

    printf("Before :: num1 = %u   num2 = %u \n" ,num1, num2);
    
    swap_bits_of_two_nums(&num1 , &num2);
    
    printf("After :: num1 = %u   num2 = %u \n" ,num1, num2);
    
    exit(0);

}