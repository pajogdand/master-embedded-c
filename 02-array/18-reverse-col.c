#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Reverse col elements
#define ROW 3
#define COL 4

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

int main(void)
{
    

    exit(0);
}