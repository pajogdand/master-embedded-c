#include <stdio.h>
#include <stdlib.h>

int main()
{
    static int a[5];
    int i =0;
    a[i] = ++i;

    printf("%d %d" , a[0],a[1]);
    
    exit(0);
}