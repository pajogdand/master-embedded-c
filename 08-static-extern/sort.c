#include <stdio.h>
#include <stdlib.h>


// void get_size(int *size)
// {
//     printf("Enter size\n");
//     scanf("%d" , size);
// }

void get_array(int * p_array , int size)
{    
    p_array = malloc(size*sizeof(int));
    
    if(p_array == NULL)
    {
        printf("Unable to allocate the memory");
        exit(-1);
    }
}

void input_array(int * p_array , int size)
{

    for(int i=0;i<size;i++)
    {
        *(p_array + i) = rand();
    }
}


void out_array(int * p_array , int size)
{
    for(int i = 0; i<size ; i++)
    {
        printf(" %d \n" , p_array[i]);
    }

}