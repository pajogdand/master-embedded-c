#include <stdio.h>
#include <stdlib.h>

#define ULL_SIZE    8
#define UINT_SIZE   4
#define USHORT_SIZE 2
#define UCHAR_SIZE  1
int main()
{
    unsigned long long num = 0x1020304050607080;

    printf("first byte = %hhx \n" , *((char*)(&num)));
    for(int i=0;i<ULL_SIZE;i++)
    {
        printf("byte = %hhx \n" , *((char*)(&num)+i));
    }

    puts("===============");    
    for(int i=0;i<ULL_SIZE;i=i+UINT_SIZE)
    {
        printf("U INT byte = %x \n" , *(unsigned int*)((char*)(&num)+i));
    }

    puts("===============");    
    for(int i=0;i<ULL_SIZE;i=i+USHORT_SIZE)
    {
        printf("U SHORT byte = %x \n" , *(unsigned short*)((char*)(&num)+i));
    }

    exit(0);
}