#include <stdio.h>
#include <stdlib.h>

#define size 7
int main(void)
{
    char a[size]={'p', 'r' , 'a' , 'v' , 'i' , 'n', '\0'};

    for(int i=0;i<size ; i++)
    {
        printf("%c" , a[i]);
    }

    printf("%s" , a);

    exit(0);
}