//(unsigned long long int)(&((struct A*)0)->a)

// (unsigned long long int)(&(((struct B*)0)->arr2))

// LINUX KERNEL 

#include <stdio.h> 
#include <stdlib.h> 

#define OFFSET_OF(T, x) (unsigned long long int)(&(((T*)0)->x))

struct A 
{
    int a; 
    char b; 
    float c; 
    float d; 
    int arr[5]; 
}; 

struct B
{
    short s1, s2; 
    int arr1[5]; 
    double arr2[5]; 
}; 

int main(void)
{
    unsigned long long int off_d; 
    unsigned long long int off_arr2; 

    off_d = OFFSET_OF(struct A, d); 
    off_arr2 = OFFSET_OF(struct B, arr2); 

    printf("offset of d in struct A = %llu\n", OFFSET_OF(struct A, d)); 
    printf("offset of arr2 in struct B = %llu\n", OFFSET_OF(struct B, arr2)); 
    return (0); 
}


