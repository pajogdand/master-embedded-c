#include <stdio.h> 
#include <stdlib.h> 

/* 
    Offset of macro: 
    Use? Given a structure name and member name, 
    the offset of macro returns the 'OFFSET' of member 
    relative to a given structure WITHOUT creating 
    an instance or a pointer of a structure 

    #define OFFSET_OF(type, mem) (unsigned long long int)((&((type*)0)->mem)
*/ 

/* 
    Container of macro: 
    You have been given a structure name, 
    member name and an address of the member 
    in one of the structure instances. 

    You have to find the base address of instance 

    struct A { int a; char b; float c; }

    struct A inA1, 
    struct A inA2; 
    struct A inA3; 

    addr is address of 'c' field of one of the structure 
    instances

*/ 
    
#define OFFSET_OF(type, member)             ((unsigned long long int)(&(((type*)0)->member)))
#define CONTAINER_OF(addr, type, member)    ((type*)(((unsigned long long int)addr) - OFFSET_OF(type, member)))

struct A 
{
    int a; 
    char b; 
    float c; 
}; 

void print_instance(float* pf); 

int main(void)
{
    struct A inA1 = {10, 'A', 1.1f}; 
    struct A inA2 = {20, 'B', 2.2f}; 
    struct A inA3 = {30, 'C', 3.3f}; 

    float* pf1 = &inA1.c; 
    float* pf2 = &inA2.c; 
    float* pf3 = &inA3.c; 

    print_instance(pf3); 
    print_instance(pf2); 
    print_instance(pf1); 

    return (0); 
}

void print_instance(float* pf)
{
    struct A* pA = NULL; 

    pA = CONTAINER_OF(pf, struct A, c); 

    pA = (struct A*)((unsigned long long int)pf - (unsigned long long int)(&((struct A*)0)->c)); 

    printf("pA->a = %d, pA->b = %c, pA->c = %.3f\n", pA->a, pA->b, pA->c); 
}
