#include <stdio.h>
#include <stdlib.h>

#define size 7
int main(void)
{
    char *a = "pravin";

    for(int i=0;i<size ; i++)
    {
        printf("%c" , a[i]);
    }

    printf("%s" , a);

    exit(0);
}