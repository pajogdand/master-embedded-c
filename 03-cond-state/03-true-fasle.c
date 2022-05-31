#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Any non zero value we can treat that as true value

// TRUE  ==> 1
// FALSE ==> 0


int main()
{
    int x = 20;
    int y = 15;
    int z = -10;

    int result =  (x == y);
    printf("result = %d" , result);
    
    // if(x == y)
    // {
    //     printf("true\n");
    // }
    // else
    // {
    //     printf("false\n");
    // }

    exit(0);
}

