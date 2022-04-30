#include <stdio.h>
#include <stdlib.h>

// https://www.youtube.com/watch?v=qoI26oy8MeI
// Check if array is subarray or not

#define SUC 1
#define FAIL 0
int isSubArray(int *arr , int *sub_arr ,int size , int size_sub_arr );
int main()
{
    int A[10] = {0,12,3,4,5,6,78,345,68,9};
    int sub_arr[3] = {4,5,6};
    int size = 10;
    int size_sub_arr = 3;
    if (isSubArray(A , sub_arr, size, size_sub_arr))
    {
        printf("Subarray\n");
    }

    exit(0);
}

int isSubArray(int *arr , int *sub_arr, int size , int size_sub_arr)
{

    if(size_sub_arr > size)
    {
        return FAIL;
    }
    if(size == 0)
    {
        return SUC;
    }
    
    int flag = FAIL;
    for(int i = 0; i< size ; i++)
    {
        if(arr[i] == sub_arr[0])
        {            
            for(int j=1 ;j<size_sub_arr ; j++)
            {
                if(arr[i+j] == sub_arr[j])
                {
                    flag = SUC;
                }
                else
                {
                    flag = FAIL;
                }      
            }
            if(flag == SUC)
            {
                break;
            }
        }
    }
    
    return flag;
    
}