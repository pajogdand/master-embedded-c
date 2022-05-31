#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// https://www.youtube.com/watch?v=qoI26oy8MeI
// Check if array is subarray or not

#define SUC 1
#define FAIL 0
int isSubSeq(int *arr , int *sub_arr ,int size , int size_sub_arr );
int *find_mis_match(int *arr, int size , int *ret_array_size);
int main()
{
    int A[10] = {0,12,3,4,5,6,78,345,68,9};
    int size = 10;
    
    int sub_arr[3] = {78 , 12 , 100};
    int size_sub_arr = 3;
    if (isSubSeq(A , sub_arr, size, size_sub_arr))
    {
        printf("subset\n");
    }
    else{
        printf("not subset\n");
    }
    
    int arr[5] = {1,2,2,4};
    size = 4;
    int ret_array_size;
    int *ret_arr = find_mis_match(arr , size , &ret_array_size);

    for(int i=0 ; i< ret_array_size ; i++)
    {
        printf("mis-match =%d \n" , ret_arr[i]);
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
    for(int i = 0; i<size ; i++)
    {
        for(int j=0 ; j<size_sub_arr ; j++)         
        {
            if(arr[i] == sub_arr[j])
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
    }
    
    return flag;
    
}

int *find_mis_match(int *arr , int size , int *ret_array_size)
{
    int cnt = 0;
    int *ret_arr =(int *)malloc(sizeof(int)*size);
    if(ret_arr == 0)
    {
        printf("Error in allocating memory \n");
        exit(-1);
    }
    // memset(ret_arr,0,size);
    for(int i=0;i<size;i++)
    {
        ret_arr[i] = 0;
    }
    for(int i=1;i<size;i++)
    {
        if((arr[i-1] != i))
        {
            ret_arr[cnt++] = i;
        }
        else if(arr[i] != arr[i-1])
        {
            ret_arr[cnt++] = arr[i];
        }
    }
    *ret_array_size = cnt -1;
    ret_arr= (int*) realloc(ret_arr, sizeof(cnt)*sizeof(int));
    return ret_arr; 
}