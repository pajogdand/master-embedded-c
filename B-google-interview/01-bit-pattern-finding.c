#include <stdio.h>
#include <stdlib.h>


unsigned int set_bits_in_range(unsigned int orginal_value ,unsigned int start_pos , unsigned int end_pos , unsigned int value)
{
    printf("processing %d , %d , %d , %d" , orginal_value, start_pos ,end_pos,  value);
    for(int i=start_pos;i<=end_pos;i++)
    {
        printf("Processing %dth bit \n" , i);
        if( ((1 << i) & value) )
        {
            printf("value at bit position %d is 1\n" , i);
            orginal_value = orginal_value | (1 << i);
        }
    }
    printf("Result = %d \n",orginal_value );
    return orginal_value;
}

unsigned int get_mask(unsigned int start , unsigned int end)
{
    unsigned int mask = 0;

    int offset = end-start+1;

    mask = ~(~0 << offset);
    mask = mask << start;

    return mask;
}

unsigned int set_bits_in_range_without_for_loop(unsigned int orginal_value ,unsigned int start_pos , unsigned int end_pos , unsigned int value)
{
    printf("processing %d , %d , %d , %d" , orginal_value, start_pos ,end_pos,  value);
    unsigned int right_shifted, left_shifted = 0;
    printf("Result = %d \n",orginal_value );
    return orginal_value;
}
int main()
{
    unsigned int orginal_value=0;
    unsigned int value = 7;
    unsigned int start_pos = 1;
    unsigned int end_pos = 3;
    // printf("result = %d \n", set_bits_in_range(orginal_value , start_pos ,end_pos ,value));
    printf("result = %d \n", get_mask(start_pos , end_pos));
    exit(0);
}