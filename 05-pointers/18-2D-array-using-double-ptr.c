#include <stdio.h>
#include <stdlib.h>

#define R 3
#define C 4
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
int main(void)
{
    int **arr_2d = (int **)malloc(R*sizeof(int *));
    
    for(int i =0;i<R;i++)
    {
        arr_2d[i] = (int *)malloc((C+i)*sizeof(int));
    }

    for(int i=0 ;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            arr_2d[i][j] = i+j;
        }
    }

    for(int i=0 ;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            printf("%d \t" , arr_2d[i][j]);
        }
        printf("\n");
    }

    int nums[3] = {1,2,3};

    int numSize = 3;
    int *returnSize;
    int **returnColumnSizes;
    subsets(nums, numSize , returnSize,returnColumnSizes);
    exit(0);
}


int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{

    puts("in function subsets\n");
    
    int **ret_arr = (int **)malloc(3*sizeof(int *));

    for(int i=0;i<3;i++)
    {
        ret_arr[i] = malloc(sizeof(int) * numsSize);
    }
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<numsSize ;j++)
        {
            ret_arr[i][j] = nums[j];
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<numsSize ;j++)
        {
            printf(" %d \t" , ret_arr[i][j]);
        }
        printf("\n");
    }


}