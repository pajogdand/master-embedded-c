#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//  Assume 0th bit position is refered by 0 number and not by 1
unsigned int get_num_of_continious_1_in_range(unsigned int start , unsigned int end)
{
    unsigned int out =0;
   
    for(int i=start;i<=end;i++)
    {
        out = out | (1 << i);
    }
    return out;
}

unsigned int get_num_of_continious_1_in_range_with_forloop(unsigned int start , unsigned int end)
{
    int offset = end-start+1;

    int out = ~(~0 << offset);

    out = out << start;

    return out;
}

int main()
{
    int start = 1;
    int end = 3;
    printf("in = %d \n" , get_num_of_continious_1_in_range(start,end));       
    printf("in = %d \n" , get_num_of_continious_1_in_range_with_forloop(start,end)); 
    exit(0);
}