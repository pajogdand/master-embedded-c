#include <stdio.h>
#include <stdlib.h>

#define MAX 7
#define MIN 0

int random(int min, int max){
   return rand() % (max + 1 - min) + min ;
}



int main()
{   
    int *A = calloc(MAX , sizeof(int));

    
    for(int i=0;i<5;i++)
    {
        int r_num = random(0,7);
        printf("random = %d \n" , r_num);
        if(A[r_num] != 1)
            A[r_num] = 1;
        else
            printf("r_num = %d is repeated there" , r_num);        
    }

    exit(0);
}