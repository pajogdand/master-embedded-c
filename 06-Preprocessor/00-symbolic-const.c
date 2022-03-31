#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define C 500
#define NAME "PRAVIN"

int main()
{
    int x,y,z;

    x =  SIZE;
    y = C;
    z = SIZE + C;

    printf("x = %d , z = %d \n" , x, z);

    char *p =  (char *)malloc(sizeof(char)*7);
    strcpy(p,NAME);
    printf("%s" , p);
    free(p);
    p = 0;


    exit(0);
}