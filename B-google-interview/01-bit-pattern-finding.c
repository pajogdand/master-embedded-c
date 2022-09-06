#include <stdio.h>
#include <stdlib.h>


unsigned int set_orignal_value(unsigned int orginal_value ,unsigned int start_pos , unsigned int end_pos , unsigned int value)
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

int main()
{
    unsigned int orginal_value=0;
    unsigned int value = 7;
    unsigned int start_pos = 1;
    unsigned int end_pos = 3;
    printf("result = %d", set_orignal_value(orginal_value , start_pos ,end_pos ,value));
    exit(0);
}