#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 3
#define COL 5

int **create_2d_array();
void init_2d_array(int ** , int r, int  c);
void print_2d_array(int ** , int r, int c);
void set_2d_array(int ** , int r, int c);
void print_row_of_array(int ** , int r, int c);
int *get_nth_row(int ** , int n);
int *get_nth_col(int ** , int n);

void print_1d_array(int *, int size);
void free_1d_array(int *);
void free_2d_array(int **);

//https://leetcode.com/problems/reshape-the-matrix/
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes);


int main()
{
    int **p_arr = create_2d_array();
    print_2d_array(p_arr , ROW, COL);
    init_2d_array(p_arr , ROW , COL);
    print_2d_array(p_arr, ROW , COL);
    set_2d_array(p_arr , ROW , COL);
    print_2d_array(p_arr, ROW, COL);
    print_row_of_array(p_arr , ROW ,COL);
    
    // int  *p_1d_arr = get_nth_row(p_arr , 0);
    // print_1d_array(p_1d_arr , COL);
    // // free_1d_array(p_1d_arr);

    // p_1d_arr = get_nth_col(p_arr, 0);
    // if(!p_1d_arr)
    //     printf("Unable to get col\n");
    // print_1d_array(p_1d_arr, ROW);
    // // free_1d_array(p_1d_arr);

    // int matColSize = COL;
    // int returnSize = 0 ;
    // int **returnColumnSizes = NULL;

    // int r = 1;
    // int c = 4;

    // int **ret_arr = matrixReshape(p_arr, ROW*COL , &matColSize, r, c,&returnSize , returnColumnSizes);

    

    exit(0);
}
void free_1d_array(int *p_arr)
{
    if(p_arr != NULL)
    {
        free(p_arr);
        p_arr = NULL;
    }
    else
    {
        printf("could not free the 1D array\n");
    }
}

int **create_2d_array()
{
    int **p = (int **)malloc(sizeof(int *) *COL);
    if(p == NULL)
    {
        printf("Error in allocating 2d array");
        exit(-1);
    }
    for(int i=0;i<COL;i++)
    {
        p[i] = (int *)malloc(sizeof(int)*ROW);
        if(p[i] == NULL)
        {
            printf("Error in allocating 2d array");
            exit(-1);
        }
    }
    
    return p;
}

void init_2d_array(int **p_arr , int r, int c)
{
    puts("====== Initilizting the 2d array with 0 =========");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            p_arr[i][j] = 0;
        }
    }    
}

void print_2d_array(int **p_arr , int r , int c)
{
    puts("======= 2D array ==========");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d\t",p_arr[i][j]);
        }
        printf("\n");
    }    
}

int *get_nth_row(int **p_arr , int n)
{
    int *p_ret_arr = (int *)malloc(sizeof(int)*n);
    puts("===================");
    int cnt = 0;
    for(int i=0;i<ROW ;i++)
    {
        for(int j=0;j<COL ;j++)
        {
            if(i == n)
                p_ret_arr[cnt++] = p_arr[i][j];           
        }
    }
    return p_ret_arr;
}


void print_1d_array(int *p_arr , int size)
{
    puts("========= printing 1D array ===========");
    
    for(int i=0;i<size;i++)
    {
        printf("%d\t" ,p_arr[i]);
    }
    printf("\n");
}


void free_2d_array(int **p_arr)
{
    if(p_arr)
        free(p_arr);
    else
        printf("could not free 2D array");
}

void set_2d_array(int **p_arr , int r, int c)
{    
    for(int i=0;i<r ;i++)
    {
        for(int j=0;j<c ;j++)
        {
            p_arr[i][j] = rand();           
        }
    }
}

int * get_nth_col(int **p_arr , int n)
{
    int *p  = (int *)malloc(sizeof(int)*ROW);
    int ind = 0;
    for(int i=0;i<ROW ;i++)
    {
        for(int j=0 ; j<COL ; j++)
        {
            if(j==n)
            {
                p[ind++] = p_arr[i][j]; 
            }
        }
    }
    return p;
}

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes)
{
    int mat_c = (*matColSize);
    int mat_r = matSize/(*matColSize);

    print_2d_array(mat, mat_r , mat_c);
    set_2d_array(mat, mat_r, mat_c);
    print_2d_array(mat, mat_r , mat_c);    

    int **ret_array = create_2d_array(r,c);
    init_2d_array(ret_array , r, c);
    print_2d_array(ret_array , r, c);
    
    // int *p = ret_array;
    // int *q = mat;
    int idx = 0;
    // for(int i=0, i_r = 0;i<mat_c;i=i+1)
    // {        
    //    memcpy(&ret_array[idx][], mat+i ,sizeof(int)*mat_c);
       
          
    // }
    printf("ret_array\n");
    print_2d_array(ret_array, r,c);    

}

void print_row_of_array(int ** p_arr, int r, int c)
{
    puts("========= printing 2D array using pointers ===========");
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            printf( "%d\t" , *(*(p_arr+i*COL)+j));
        }
        printf("\n");
    }
}