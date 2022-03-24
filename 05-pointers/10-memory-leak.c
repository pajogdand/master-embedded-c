#include <stdio.h>
#include <stdlib.h>

int *create_int(int);

int main(void)
{
    int *p;
    p = 0;

    p = create_int(100);
    printf("data in p = %d" , *p);

    free(p);
    p = 0;
    
    exit(0);
}


int * create_int(int x)
{
    int *in_p;
    in_p = 0;

    in_p = malloc(sizeof(int));
    *in_p = 0;

    return (in_p);    

}