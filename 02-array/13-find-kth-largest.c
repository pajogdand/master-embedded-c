#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// https://leetcode.com/problems/kth-largest-element-in-an-array/
// Check if array is subarray or not
#define size 7
int find_kth_larget_element(int *a , int l , int k)
{
    int largest = INT_MIN;
    int kth_largest;
    int pass = k;
    while(pass !=0 )
    {
        if(pass == k)
        {
            for(int i=0;i<l;i++)
            {
                if(a[i] > largest)
                {
                    largest = a[i];
                }
            }
            kth_largest =  largest;
        }
        else{
            int diff = largest - a[0];
            for(int i=1;i<l;i++)
            {                
                if( ((largest-a[i]) < diff) && ( (largest-a[i]) >0) )
                {
                    diff = largest-a[i];
                    kth_largest = a[i];
                }
            }
            largest = kth_largest;        
        }
        pass--;
    }
    return kth_largest;
    
}
int main(void)
{
    
    int A[size]={ 2, 5 ,4 , 10, 11 ,8 , 2};
    int k = 5;
    printf(" find_kth_larget_element = %d \n", find_kth_larget_element(A , size , k));
    
    exit(0);
}