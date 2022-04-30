#include <stdio.h>
#include <stdlib.h>

int one(int);
int two(int);
int three(int);
int main()
{
    int (*arr[3])(int);

    arr[0] = &one;
    arr[1] = &two;
    arr[2] = &three;

    for(int i=0;i<3;i++)
    {
        printf("%d \n" , arr[i](i));
    }

    exit(0);    
}

int one(int x)
{
    return x;
}

int two(int x)
{
    return x;
}

int three(int x)
{
    return x;
}