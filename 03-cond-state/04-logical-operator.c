#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Any non zero value we can treat that as true value
// zero value we can treat that as false value

// TRUE  ==> 1
// FALSE ==> 0

// There are 3 logical operators in C language.
// They are, logical AND (&&), logical OR (||) and logical NOT (!) and logical XOR (^)

// S1 && S2  result
// T     T    T
// T     F    F
// F     T    F
// F     F    F

// S1 || S2  result
// T     T    T
// T     F    T
// F     T    T
// F     F    F

// !(TURE)  ==> FALSE
// !(FALSE) ==> TRUE

// Target : (x is equal to y) and (a is equal to b)  ==> "NO"
// Target : (x is equal to y)  or (a is equal to b)  ==> "NO"
int main()
{
    int x = 20;
    int y = 20;

    int a = 10;
    int b = 45;
    
    int z = 12;
    if(z)
    {
        printf("z is True : %d\n" , z);
    }
    else{
        printf("z is false : %d\n" , z);
    }

    z = !z;
    if(z)
    {
        printf("z is True: %d\n" , z);
    }
    else{
        printf("z is false: %d\n" , z);
    }    

    // int result1  = ( (x == y) || (a == b));
    //                 // T           F        ==> T
    // int result  = ( (x == y) && (a == b));
    //                 // T           F        ==> F           
    // printf("result = %d\n" , result);

    

    // if(result)
    // {
    //     printf("result is True\n");
    // }
    // else{
    //     printf("result is false\n");
    // }



    exit(0);
}

