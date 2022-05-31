#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int find_largest_element_in_array(int *p , int size)
{
    int largert = INT_MIN;
    for(int i=0;i<size;i++)
    {
        if(p[i] > largert)
        {
            largert = p[i];
        }
    }

    return largert;
}

int find_smallest_element_in_array(int *p , int size)
{

    int smallest = INT_MAX;

    for(int i=0;i<size ; i++)
    {
        if(p[i] < smallest)
        {
            smallest  = p[i];
        }
    }

    return smallest;
}

float find_avg_of_array_elements(int *p , int size)
{
        float avg =0;
        
        for(int i=0;i<size ;i++)
        {
            avg += p[i];
        }

        avg = avg/size;

        return avg; 
}

bool is_element_present(int *p , int size, int target)
{
    for(int i=0;i<size;i++)
    {
        if(p[i] == target)
            return true;
    }

    return false;
}

bool is_contain_negative_elements(int *p, int size)
{

    for ( int i = 0 ; i< size ;i++)
    {
        if(p[i] < 0)
        {
            return true;
        }
    }

    return false;
}

bool is_sub_array_present(int *p , int * sub_array , int size , int size_sub_array)
{
    if(size_sub_array > size)
    {
        printf("error with size\n");
        return false;
    }
        
    bool is_found = false;
    int cnt = 0;
    for(int i =0; i<size; i++)
    {
        for(int j=0;j<size_sub_array ;j++)
        {                
            if(p[i+j] == sub_array[j])
            {
                cnt++;
            }
        }
        if(cnt == size_sub_array)
            return true;            
    }
    return false;
}

int num_of_sub_array_present(int *p , int * sub_array , int size , int size_sub_array)
{
    int num_of_sub_array = 0;
    if(size_sub_array > size)
    {
        printf("error with size\n");
        return false;
    }
    int cnt = 0;
    for(int i=0; i<size; i++)
    {
        for(int j=0;j<size_sub_array ;j++)
        {                
            if(p[i+j] == sub_array[j])
            {
                cnt++;
            }
        }
        if(cnt == size_sub_array)
        {
            num_of_sub_array++;         
            cnt = 0;
        }
    }
    return num_of_sub_array;
}

//https://leetcode.com/problems/maximum-product-subarray/
int maxProduct(int* nums, int size){
    int largest_product = INT_MIN;
    int sub_array_product = 1;
    if(size < 0)
    {
        return -1;
    }
    for(int i=0; i<size ; i++)
    {
        for(int j=i+1;j<size ;j++)
        {
            if(j == i+1)
            {
                sub_array_product = nums[i] * nums[j] ;
            }
            else
            {
                sub_array_product = sub_array_product * nums[j];
            }
            if(sub_array_product > largest_product)
            {
                largest_product = sub_array_product;
            }
        }
        sub_array_product = 1;
    }
    return largest_product;
}

int *getRow(int rowIndex, int* returnSize)
{
    int peramid_size = rowIndex + 1;
    int *p_arr =(int *)malloc(sizeof(peramid_size));
    *returnSize =  peramid_size;

    

    for(int i=0;i<peramid_size ;++i)
    {
        if(i==0 || i==(peramid_size-1))
        {
            p_arr[i] = 1;
        }

    }
}

int main(void)
{
    int size = 8;
    int A[8]= {2,3,-2,4,3,-2,10,11};

    printf("find_largest_element_in_array = %d \n" , find_largest_element_in_array(A,size));

    int sub_array[2] = {3,-2};
    printf("find_largest_element_in_array = %d \n" , is_sub_array_present(A,sub_array, size ,2));
    
    // int sub_array[2] = {3,-2};
    printf("num_of_sub_array_present = %d \n" , num_of_sub_array_present(A,sub_array, size ,2));

    int t[4] = {2,3,-2,4};
    printf("maxProduct = %d \n" , maxProduct(t,4));
    exit(0);    
}