#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

unsigned int get_size_array(int range)
{
    unsigned int r = range/sizeof(unsigned int);
    return r;
}

unsigned int get_quotient(unsigned int range)
{
    return range/(sizeof(unsigned int));
}

unsigned int get_reminder(unsigned int range)
{
    return range%(sizeof(unsigned int));
}

int main()
{
    int range =  32000;
    unsigned int r = get_size_array(range);

    unsigned int *bit_array_of_dec_num = (unsigned int *)calloc(r,sizeof(unsigned int));

    unsigned int input_arr[]={0 ,10,20,300,1000,300,2000,10,32000};

    unsigned int index_pos = 0;
    unsigned int bit_pos = 0;
    
    for(int i=0;i<SIZE;i++)
    {
        index_pos = get_quotient(input_arr[i]);
        bit_pos = get_reminder(input_arr[i]);

        // check if decimal position in array is set or not
        // it was not set , means the input_arr element found first time
        if( !( bit_array_of_dec_num[index_pos] & (1 << bit_pos)) )
        {
            printf("%d is found first time \n" , input_arr[i]);
            bit_array_of_dec_num[index_pos]  = bit_array_of_dec_num[index_pos] | (1 << bit_pos);
        }
        else
        {
        // if not then it was occured previously
            bit_array_of_dec_num[index_pos] = bit_array_of_dec_num[index_pos] | (1 << bit_pos);
        }
    }

    exit(0);
}