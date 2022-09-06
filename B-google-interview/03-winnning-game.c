// A[i] = j , is an array of N elements(starting from -1 to N) which represents winning squeance ID
// for e.g N  = 
// [5 4 2 -1 3 1 6 0]
// [0 1 2  3 4 5 6 7]
// [3 4 1  6 5 0 7 ]


// find index of  -1;
// out[0] = index_of(A[-1])
// find index of [out[0]]
// out[1] =  index_of[out[0]]

#include <stdio.h>
#include <stdlib.h>

#define SIZE 3+2
int get_index_of_element(int *P ,int eletment , int size)
{
    for(int i=0;i<size;i++)
    {
        if(eletment == P[i])
        {
            return i;       
        }
    }
}

int main()
{
    int A[] = {-1, 0, 1, 3, 2};
    
    int out[SIZE] = {};
    
    
    for(int i=0;i<SIZE-1;i++)
    {
        if(i == 0)
            out[i] = get_index_of_element(A , -1 , SIZE);
        else
            out[i] = get_index_of_element(A , out[i-1] , SIZE);      
    }

    for(int i=0 ;i<SIZE;i++)
    {
        printf("%d \t" , out[i]);
    }
    
    exit(0);
}
