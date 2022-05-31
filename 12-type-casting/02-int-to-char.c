#include <stdio.h>
#include <stdlib.h>

int main()
{

    unsigned int num = 0x0a0b0cd0;

    unsigned char c = (char)num;

    printf("x = %hhx \n" , c);
    

    exit(0);
}