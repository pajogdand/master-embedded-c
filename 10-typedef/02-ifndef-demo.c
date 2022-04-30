#include <stdio.h>
#include <stdlib.h>

#ifndef PRJ
void pravin_jogdand(void);
#endif

int main(void)
{
    #ifndef PRJ
    pravin_jogdand();
    #endif
    exit(0);
}

#ifndef PRJ
void pravin_jogdand(void);
{
    puts("Hi there");
}
#endif