#include <stdio.h>
#include <stdlib.h>

// https://www.youtube.com/watch?v=qoI26oy8MeI
// Check if array is subarray or not

#define SUC 1
#define FAIL 0
int isSubSeq(int *arr , int *sub_arr ,int size , int size_sub_arr );
int main()
{
    int A[10] = {0,12,3,4,5,6,78,345,68,9};
    int size = 10;
    
    int sub_arr[3] = {78 , 4};
    int size_sub_arr = 2;
    if (isSubSeq(A , sub_arr, size, size_sub_arr))
    {
        printf("Subarray\n");
    }

    exit(0);
}

int isSubSeq(int *arr , int *sub_arr, int size , int size_sub_arr)
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
    int cnt = 0;
    for(int i = 0; i< size ; i++)
    {         
        if(arr[i] == sub_arr[cnt])
        {
            cnt++;
            flag = SUC;
            if(cnt == size_sub_arr) 
                return flag;
        }
        else
        {
            flag = FAIL;
        }      

    }
    
    return flag;
    
}