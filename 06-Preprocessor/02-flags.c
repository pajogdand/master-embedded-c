#include <stdio.h>
#include <stdlib.h>

#define FIRST_BIT_ON  1
#define SECOND_BIT_ON 2
#define THIRED_BIT_ON 4

void detect_flags(int flags);
int main(void)
{
    
    int x;
    x = FIRST_BIT_ON | SECOND_BIT_ON ;

    printf("value if x = %d \n" , x);

    if(THIRED_BIT_ON == 4 )
    {
        printf("condition has matached\n");
    }

    // detect_flags(1);
    // detect_flags(2);
    // detect_flags(4);
    
    int y;
    y = FIRST_BIT_ON | SECOND_BIT_ON;
    detect_flags(y);

    exit(0);
}

void detect_flags(int flags)
{
    if( (flags & FIRST_BIT_ON ) == FIRST_BIT_ON )
        puts(" first bit is set");
    if( (flags & SECOND_BIT_ON ) == SECOND_BIT_ON )
        puts(" second bit is set");
    if( (flags & THIRED_BIT_ON ) == THIRED_BIT_ON )
        puts(" third bit is set");    
}