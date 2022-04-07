#include <stdio.h>
#include <stdlib.h>


int create_int_using_dpp(int **p, int num);

int main (void)
{
    int *p_main;
    int num = 30;

    create_int_using_dpp(&p_main , num);
    
    printf("num value in p = %d" , *p_main);
    free(p_main);


    exit(0);
}

int create_int_using_dpp(int **p ,int num)
{

    *p = (int *)malloc(sizeof(int));

    if(*p == NULL)
    {
        printf("mem allocation failed\n");
        exit(-1);
    }

    **p =  num;
    
    free
}