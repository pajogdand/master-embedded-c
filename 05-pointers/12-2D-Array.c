#include <stdio.h>
#include <stdlib.h>

#define NR 4
#define NC 3

#define SUCCESS 1
#define INVALID_ROW_NUM 2
#define INVALID_COL_NUM 3

int initialize(int [NR][NC] , int no_rows , int no_cols);
int sum_row(int [NR][NC] , int no_rows , int no_cols , int row , int *sum);
int sum_col(int [NR][NC] , int no_rows , int no_cols , int col , int *sum);

int main(void)
{
    int A[NR][NC];
    
    initialize(A, NR, NC);
       

    exit(0);
}


int initialize(int A[NR][NC], int no_rows, int no_cols)
{

  for(int i=0;i<no_rows ; i++)
  {
      for(int j=0; j<no_cols ; j++)
      {
          A[i][j] = (i+1)+j;
          printf(" %d " , A[i][j]);
      }
      printf("\n");
  }
}

int sum_row(int A[NR][NC] , int no_rows , int no_cols , int row , int *sum)
{

    if(row > no_rows)
    {
        printf("Error\n");
        return(INVALID_ROW_NUM);
    }
    
    for(int j=0;j<no_cols;j++)
        *sum =  *sum + A[row][j];
    
    return SUCCESS;

}

int sum_col(int A[NR][NC] , int no_rows , int no_cols , int col , int *sum)
{
    
    if(col > no_cols)
    {
        printf("Error\m");
        return(INVALID_COL_NUM);
    }
    
    for(int j=0;j<no_cols;j++)
        *sum =  *sum + A[j][col];
    
    return SUCCESS;

}