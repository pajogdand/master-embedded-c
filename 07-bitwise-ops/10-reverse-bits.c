#include <stdio.h>
#include <stdlib.h>

/*Write a program to reverse all bits of given integer*/

unsigned int swap_bits(unsigned int num)
{
    unsigned int ret = 0;
    for(int i=0 ; i<32; i++)
    {
        if( (num & (1<<i) ) )
        {
            ret = ret | (1 << (31 -i));
        }
    }
     
    return ret;
}

int main(void)
{
    unsigned int num = 1;

    printf("Before = %u \n" ,num);
    unsigned int ret = 0;
    ret = swap_bits(num);
    printf("After = %u \n" ,ret);
    
    exit(0);

}