#include <stdio.h>
#include <stdlib.h>


//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    
    int *ret_arr = (int *)malloc(sizeof(int)*2);
    ret_arr[0] = ret_arr[1] = -1;
    
    if(numsSize == 0 && target == 1)
    {
        return ret_arr;
    }    
    
    int j=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i] == target)
        {
            ret_arr[j] = i;
            j++;
        }
    }
    return ret_arr;

}
int main()
{

    int nums[] = {5,7,7,8,8,10};
    
    int target = 8;

    int *returnSize;

    int *p_ret_array = searchRange(nums,6, 8, returnSize);

    printf("output [%d %d] \n", p_ret_array[0] , p_ret_array[1] );
    
    exit(0);
}