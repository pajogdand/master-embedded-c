#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int find_num_of_digit(int in)
{
    
    int cnt = 0;
    do
    {
       in = in/10;
       cnt++;
    }while(in !=0);

    return cnt;

}

int main(void)
{
    
    int in = 1234;    

    int num_of_digits;
    num_of_digits = find_num_of_digit(in);

    printf("number of digits = %d" ,num_of_digits);

    int * p_digits = (int *) malloc(num_of_digits*sizeof(int));
    int digit;
    int i = 0;
    while(in != 0)
    {
        int digit = in%10;
        in = in /10;
        printf("digit = %d \n", digit);
        p_digits[i] = digit;
        i++;
    }

    int first= p_digits[0];
    for(int j=0;j<num_of_digits;j++)
    {
        if(first >p_digits[j])
        {
            int temp=p_digits[j];
            p_digits[j] = first;
            p_digits[0]=temp;
            break;

        }
    }
    
    for(int i=0;i<4;i++)
    {
        printf("modified digits = %d\n" , p_digits[i]);
    }

    int ret = 0;
    for(int i=0;i<4;i++)
    {
        ret = ret + (p_digits[i])*(pow( 10, i ));
    }
    printf("modified number = %d \n", ret);

    exit(-1);
}