// struct A 
// {
//     int a; 
//     char b; 
//     float c; 
//     float d; 
//     int arr[4]; 
// }; 

// struct B
// {
//     short s1, s2; 
//     int arr[5]; 
//     double arr[5]; 
// }inB = {0x1020, 0x3040, 
//     {0xa0b0c0d0, 0xffa0ffb0ffc0, 0x1a2b3c4d, 0xff1098ff, 0x87ff10}, 
//     {1.1, 2.2, 3.3, 4.4, 5.5}}; 

#include <stdio.h>
#include <stdlib.h>


struct A{
    int a;
    char b;
    float c;
};
int main(void)
{

    struct A inA;
    printf("&inA.a = %llu\n" ,(unsigned long long int)&inA.a );
    printf("&inA.b = %llu\n" ,(unsigned long long int)&inA.b );
    printf("&inA.c = %llu\n" ,(unsigned long long int)&inA.c );
    
    struct A *pA = &inA;
    printf("&inA->a = %llu\n" ,(unsigned long long int)&pA->a );
    printf("&inA->b = %llu\n" ,(unsigned long long int)&pA->b );
    printf("&inA->c = %llu\n" ,(unsigned long long int)&pA->c );

    // without allocating any instance of struct , how we can compute the offest of its member
    struct A *p = 0;
    printf("offset of a = %llu\n" ,(unsigned long long int)&p->a );
    printf("offest of b = %llu\n" ,(unsigned long long int)&p->b );
    printf("offest of c = %llu\n" ,(unsigned long long int)&p->c );


    printf("offset of a = %llu\n" ,(unsigned long long int)&((struct A *)0)->a );
    printf("offest of b = %llu\n" ,(unsigned long long int)&((struct A *)0)->b );
    printf("offest of c = %llu\n" ,(unsigned long long int)&((struct A *)0)->c );

    // ((struct A*)&inB)->d = 0x11111111; 
    // *(short*)&(((struct A*)&inB)->d) = 0xdddd; 

    
    return (0); 
}