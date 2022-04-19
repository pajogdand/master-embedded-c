#include <stdio.h>
#include <stdlib.h>

/*Write a function to 
* count number of ON and OFF bits in a int number
*
*/
#define ON_BITS 1
#define OFF_BITS 0

int num_of_on_off_bits(int *num , int which_bits);

int main(void)
{
    int num = 1;

    int ret = num_of_on_off_bits(&num ,OFF_BITS);
    printf("number of ON/OFF bits = %d" ,ret);
    exit(0);
}

int num_of_on_off_bits(int *num , int which_bits)
{
    if(which_bits == ON_BITS)
    {
        int cnt = 0;
        for(int i=0;i<=31 ; ++i)
        {
            if( (1<<i & (*num)) != 0 )
            {
                cnt++;
            }
        }

        return cnt;
    }
    else if(which_bits == OFF_BITS)
    {
        int cnt = 0;
        for(int i=0;i<=31 ; ++i)
        {
            if( (1<<i & ~(*num)) != 0 )
            {
                cnt++;
            }
        }
        return cnt;

    }
    else{
        printf("wroung selction of bits\n");
        return -1;
    }
}

