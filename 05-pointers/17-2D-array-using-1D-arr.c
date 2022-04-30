#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4
int main(void)
{

    int *arr_2d = malloc(sizeof(int)*ROWS*COLS);
    
    for(int i=0; i<ROWS ; i++)
    {
        for(int j=0;j<COLS ; j++)
        {
            arr_2d[i*COLS +j ]  = i + j;
        }
    }

    for(int i=0; i<ROWS ; i++)
    {
        for(int j=0;j<COLS ; j++)
        {
            printf("%d\t", arr_2d[i*COLS +j ]);
        }
        printf("\n");
    }
    exit(0);
}