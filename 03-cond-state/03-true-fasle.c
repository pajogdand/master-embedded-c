#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Any non zero value we can treat that as true value

// TRUE  ==> 1 (NON ZERO)
// FALSE ==> 0 (ZERO)


int main()
{
    int x = 20;
    int y = 15;
    int z = -10;
    int f = 0;

    // int result =  (x == y);
    // printf("result = %d\n" , result);
    
    if(f)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    exit(0);
}

