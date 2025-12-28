#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    // & and 
    // |
    // ^ (XOR)
    // ~ (NOT)
    // << (Left shift)
    // >> (Right shift)
    unsigned char a = 1; 
    unsigned char b = 3;

                         // a = 00000010
                         // b = 00000011
                         // c = 00000010 &  

                         // a = 00000001
                         // b = 00000000 &
                         // c = 00000000    ==> 00 block all ones and zero ones

                        // a = 00000001
                        // b = 00000011 |
                        // c = 00000011    ==> 11 pass all ones

                         // a = 00000001
                         // b = 00000000 |
                         // c = 00000001    ==> 00 pass all ones

                        // a = 00000001
                        // b = 00000011 ^
                        // c = 00000010    ==>  Negation of input

                         // a = 00000001
                         // b = 00000000 |
                         // c = 00000001    ==> pass as it is

                         

    printf("a & b = %d\n", a & b); // AND operation


    return 0;
}


