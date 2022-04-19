#include <stdio.h>
#include <stdlib.h>

int main()
{
    // connstat value must be delclared as soon a it is declared
    // default value of const variable is 0
    const int n;
    printf("defalt value of n = %d \n");
    // n = 10; // this will not work 
    printf("defalt value of n = %d \n");

    
    const int n = 10;

    // n = 11; This will not work


}