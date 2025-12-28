#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // unsigned int n = 2; // ==> 0x00000000 00000000 00000000 00000010
    // unsigned int n_b = 0b00000000000000000000000000000010;
    // unsigned int n_h = 0x2; // Corrected hex value to match binary and decimal value

    // printf("Binary representation of n = %u, n_b = %u, n_h = %u\n", n, n_b, n_h);

    // & and   ==> if both bits are 1 then only result is 1 else 0
    // |       ==> if any one bit is 1 then result is 1 else 0
    // ^ (XOR) ==> Both bits are different then only result is 1 else 0
    // ~ (NOT)
    // << (Left shift)
    // >> (Right shift)

    unsigned char a = 1; // a = 00000001 =>  2^0 *1 ==> 
    unsigned char b = 2; // b = 00000010 =>  2^1*1 + 2^0*0
    //                          00000011
    // b = b>>1;            // b = 00000001
    printf("a = %d, b = %d\n", a, b);
    // printf("Size of a = %ld, Size of b = %ld\n", sizeof(a), sizeof(b));

    unsigned char c = a ^ b;

    printf("c = a & b = %d\n", c);
    
    // unsigned char d = 0b11111110;
    // unsigned char d = 254;
    unsigned char d = 0xFE;
    unsigned char e = ~d;
    printf("d = %d\n", d);
    printf("e = ~d = %d\n", e);
    
    //00000001
    //

    // 00000001 |
    // 00000010
    // ---------
    // 00000011
    // 00000000
    // 00000011

    // 00000001 ==> 11111110
    // 00000010 ==> 00000100
    // 00000010 ==> 00000001

    // printf("a & b = %d\n", a & b); // 0
    
    // printf("a | b = %d\n", a | b); // 3

    // printf("a ^ b = %d\n", a ^ b); // 3

    // printf("~a = %d\n", ~a); // 0b11111110

    // printf("b << 1 = %d\n", b << 1); // 4 0000 0100

    // printf("b >> 1 = %d\n", b >> 1); // 1 0000 0001

    return 0;
}


