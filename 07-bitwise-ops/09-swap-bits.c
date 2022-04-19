#include <stdio.h>
#include <stdlib.h>

/*In 32 bit number, swap the bits as follows 
Exchange 1st and 32 nd bit 
Exchange 2nd and 31st bit
Exchange 3rd and 30th bit
And so forth*/

unsigned int swap_bits(unsigned int *num)
{
    unsigned int left_temp , right_temp = 0;
    unsigned int ret = 0;
    for(int i=0 , j=31 ; (i<16) && (j>=16); i++,j--)
    {
        printf("i = %d j = %d \n" , i ,j);
        left_temp  = ( (*num) & (1 << i) ) << j;
        right_temp = ( (*num) & (1 << j) ) >> j;

        ret = ret | (left_temp) ; 
        ret = ret | (right_temp) ;
    }
     
    return ret;
}

int main(void)
{
    unsigned int num = 2;

    printf("Before = %u \n" ,num);
    unsigned int ret = swap_bits(&num);
    printf("After = %u \n" ,ret);
    exit(0);
    
}