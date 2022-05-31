#include <stdio.h>
#include <stdlib.h>


// 
//  V1 <  V2 ==> less than
//  V1 >  V2 ==> Greather than
//  V1 == V2 ==> equal to
//  V1 != V2 ==> not equal


int main()
{
    int x = 20;
    int y = 10;

    if(x < y)
    {
        printf("x is less than y\n");
    }
    else{
        printf("x is not less than y");
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