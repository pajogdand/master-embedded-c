#include <stdio.h>
#include <stdlib.h>


void which_endian(unsigned int x)
{
    if(*((unsigned char *)&x) == 1)
    {
        printf("Litte Endian\n");
    }
    else if(*((unsigned char *)&x + 3) == 1)
    {
        printf("Litte Endian\n");
    }
    else{
        printf("nigther litte Endian nor big Endian\n");
    }
}
int main(void)
{

    unsigned int x = 1;
    which_endian(x);
    exit(0);
}