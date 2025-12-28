#include <stdio.h>
#include <stdlib.h>

//  V1 <  V2 ==> less than
//  V1 >  V2 ==> Greather than
//  V1 == V2 ==> equal to
//  V1 != V2 ==> not equal

// Target : given 2 variable x and y
//          check if x and y are even or not, and print message on screen
//          check if x and y number is zero of not print message on screen


// && , || 

int main()
{
    int x = 12;
    int y = 20;

    if( (x%2 == 0) && (y%2 ==0) )
    {
        printf("x and y are even\n");
        if(100)
        {
            printf("Inside nested if\n");
        }
    }
    else if (x%2 == 0 )
    {
        printf("x is even\n");
    }
    else if(y%2 == 0)
    {
        printf("x is even\n");
    }
    else
    {
        printf("x and y are odd\n");
    }

    exit(0);
}

//
// if(Statements)
// {
//     // this block
// }
// else{
//     // this block
// }