#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int convert_bin_dec(unsigned int in)
{
    unsigned int out =0;
   
    for(int i=0;i<32;i++)
    {
        if( (in & (1<<i)) )
        {
            out = out + pow(2,i);
        }
    }
    return out;
}


int main()
{
    unsigned int in_bin_number = 0b00111100;

    printf("in = %d , out = %d \n" , in_bin_number , convert_bin_dec(in_bin_number));       

    exit(0);
}