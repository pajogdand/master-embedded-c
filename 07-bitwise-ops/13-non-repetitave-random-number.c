#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10
#define MIN 0

#define TRUE 1
#define FALSE 0

// #define TEST

int random(int min, int max){
   int temp = rand() % (max + 1 - min) + min ;
    return temp;
}


int get_size_for_array(int s)
{
    if(s>0 && s<=7)
    {
        return (pow(2,8));
    }
}

unsigned char *create_bit_array_representation(int size)
{
    int i =0;
    if(size%8 == 0)
        i = size/8;
    else
        i = size/8 + 1;

    unsigned char * A =  (unsigned char *)calloc(i , sizeof(unsigned char));
    return A;
}

void set_ith_bit(unsigned char *A , int ith_bit_to_set)
{
    int array_index = ith_bit_to_set/8;
    int bit_position_inarray = ith_bit_to_set%8;

    A[array_index] = A[array_index] | (1<<bit_position_inarray);    
}

int is_ith_bit_set(unsigned char *A, int ith_bit_to_set)
{
    int array_index = ith_bit_to_set/8;
    int bit_position_inarray = ith_bit_to_set%8;

    if((A[array_index] & (1<<bit_position_inarray)) != 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
void ramd_app(unsigned char *A , int min ,int  max)
{
    for(int i=0;i<5;i++)
    {
        int r_num = (int)random(min,max);
        printf("got random number = %d \n" , r_num);
        
        if(is_ith_bit_set(A, r_num) == FALSE)
        {
            set_ith_bit(A,r_num);
            printf("%d is not repeated \n" , r_num);
            printf("=====================\n");
        }
        else
        {
            printf("%d is repeated \n" , r_num);        
            printf("=====================\n");
        }
    }

    free(A);
}


int get_next_multiple_of_8(int input_num)
{
    int next_multiple_of_8 = 0;

    if(input_num%8 == 0)
    {
        next_multiple_of_8 = input_num;
    }
    else
    {
        next_multiple_of_8 = ((input_num/8) + 1)*8;
    }
    return next_multiple_of_8;
}

int main()
{   
    // int *A = calloc(1, pow(2,8)/4);

    // if(A == NULL)
    // {
    //     printf("sorry");
    // }   
    

    int next_multiple_of_8 = get_next_multiple_of_8(MAX);
    
    unsigned char *A = create_bit_array_representation(next_multiple_of_8);

    #ifdef TEST
    int ith_bit_to_set = 2;
    set_ith_bit(A , ith_bit_to_set);

    int bit_pos=2;
    if(is_ith_bit_set(A, bit_pos) == TRUE)
        printf("%dth bit is set" , bit_pos );
    else
        printf("%dth bit is not set" , bit_pos );
    #endif
    
    ramd_app(A , MIN , MAX);
    
    exit(0);
}