#include <stdio.h>
#include <stdlib.h>

#define BITS_IN_BYTE 8
int is_kth_bit_set(unsigned int k , int  n);
int main(void)
{
    
    unsigned int n = 2;
    unsigned int k = 2;


    if(is_kth_bit_set(k,n))
    {
        printf("%d bit of %d is set" , k, n );
    }
    else
    {
        printf("%d bit of %d is not set" , k, n );
    }
    

    return 0;
}

int is_kth_bit_set(unsigned int k , int  n)
{
//    if ( ( (1 << (k-1)) & n ) != 0)
//    {
//        return 1;
//    }
//    else
//    {
//        return 0;
//    }
    int ret = ( ( (1 << (k-1)) & n ) != 0) ?  1 : 0;

    return ret;
}