#include <stdio.h>
#include <stdlib.h>

void larger(int x , int y)
{
    (x > y)?printf("x is greater than y\n") : printf("y is greater than x\n");
}
#define WHICH_IS_LARGER(X,Y)\
    ( { \
        if ( X < Y ) \
        {                              \
            printf("%d is larger\n",X); \
        } \
        else \
        { \
            printf("%d is larger\n",Y); \
        } \
      } \
    )

#define GET_LARGER(X,Y) WHICH_IS_LARGER(X,Y)
#define GET_LARGER_VIA_FUNCTION(X,Y) larger(X,Y)

int main(void)
{
    GET_LARGER(1,2);
    GET_LARGER_VIA_FUNCTION(1,2);
    return 0;
}