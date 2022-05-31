#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Any non zero value we can treat that as true value

// TRUE  ==> 1
// FALSE ==> 0

// There are 3 logical operators in C language.
// They are, logical AND (&&), logical OR (||) and logical NOT (!).

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
    
    bool result  = ( (x == y) || (a == b) );
                    // T           F    ==>  T        
    printf("result = %d\n" , sizeof(result)); 

    if(result)
    {
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }



    exit(0);
}

