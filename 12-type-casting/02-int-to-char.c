#include <stdio.h>
#include <stdlib.h>

int main()
{

    unsigned int num = 0x0a0b0cd0;

    unsigned char c = (char)num;

    printf("x = %hhx \n" , c);
    

    exit(0);
}

// 1000 2000 30000 400000 5000000
// 0a   0b   0c    d0