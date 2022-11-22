#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 5
#define COL 5

int **create_dyn_2d_array()
{
    int **p = (int **)calloc(COL ,sizeof(int *));

    for(int  i=0;i<COL ;i++)
    {
        p[i] = calloc(ROW, sizeof(int));
    }
    
    return p;
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

void init_2d_array(int **p_arr , int r, int c)
{
    puts("====== Initilizting the 2d array with 0 =========");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            p_arr[i][j] = (i+1)*j;
        }
    }    
}

void print_elements(int **p ,const char *which_type_of_elements)
{
    printf("========== %s ==========\n",which_type_of_elements);
    if(!strcmp(which_type_of_elements, "only_diagonal"))
    {
        pirntf("%s \n" ,which_type_of_elements);
        for(int i=0;i<ROW;i++)
        {
            for(int j=i ; j<=i ;j++)
            {
                printf("p[%d][%d] = %d", i, j , p[i][j]);
            }
        }
    }
    else if(!strcmp(which_type_of_elements, "strict_upper"))
    {
        pirntf("%s \n" ,which_type_of_elements);
        for(int i=0 ;i<ROW;i++)
        {            
            for(int j=i+1;j<COL;j++)
            {
                printf("p[%d][%d] = %d", i, j , p[i][j]);
            }
        }
    }

    else if(!strcmp(which_type_of_elements, "strict_upper_with_diagonal"))
    {
        pirntf("%s \n" ,which_type_of_elements);
        for(int i=0 ;i<ROW;i++)
        {            
            for(int j=i;j<COL;j++)
            {
                printf("p[%d][%d] = %d", i, j , p[i][j]);
            }
        }

    }
    else if(!strcmp(which_type_of_elements, "strict_lower"))
    {
        pirntf("%s \n" ,which_type_of_elements);
        for(int i=1 ;i<ROW;i++)
        {            
            for(int j=0;j<i;j++)
            {
                printf("p[%d][%d] = %d", i, j , p[i][j]);
            }
        }

    }
    else if(!strcmp(which_type_of_elements, "strict_lower_with_diagonal"))
    {
        pirntf("%s \n" ,which_type_of_elements);
        for(int i=0 ;i<ROW;i++)
        {            
            for(int j=0;j<i;j++)
            {
                printf("p[%d][%d] = %d", i, j , p[i][j]);
            }
        }

    }

}


int main()
{
    int **p_arr = create_dyn_2d_array();

    print_2d_array(p_arr , ROW , COL);
    init_2d_array(p_arr , ROW, COL);
    print_2d_array(p_arr , ROW , COL);
    print_elements(p_arr ,"only_digonal");

    exit(0);
}