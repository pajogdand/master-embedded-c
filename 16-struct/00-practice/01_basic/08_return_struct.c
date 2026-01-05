/*
 * File Name   : 08_return_struct.c
 * Folder      : 01_basic
 *
 * Program Name:
 *   08 return struct
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 08_return_struct.c -o 08_return_struct
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 */

#include <stdio.h>
#include <stdlib.h>
/* Structure Definition */
typedef struct
{
    int   i;
    char  c;
    float f;
} my_struct;

/* Pointer to structure */
my_struct *p_my_struct;

/* Function Prototype */
my_struct* return_struct(void);

/* Main Function */
int main(void)
{
    my_struct *ms_local_ptr = NULL; // This is not pointing to no where
    ms_local_ptr = return_struct(); // this is now pointing to heap memory location
    
    printf("In main :: i = %d , c = %c , f = %f \n" , ms_local_ptr->i , ms_local_ptr->c, ms_local_ptr->f);

    free(ms_local_ptr);

    return 0;
}

/* Function Definition */
my_struct* return_struct(void)
{
    my_struct ms = {1, 'c' , 1.1f};   
    printf("In function :: i = %d , c = %c , f = %f \n" , ms.i , ms.c, ms.f);

    // this will be issue:
    // return &ms;

    // this also be issue
    // my_struct *msp = &ms;

    // this is will be an issue
    // my_struct *msp =(my_struct *)malloc(sizeof(my_struct));
    // msp = &ms;

    // we must declare the struct in heap
    my_struct *msp =(my_struct *)malloc(sizeof(my_struct));
    if(!msp)
    { 
        printf("Issue in allocating the memory");
        return NULL;
    }

    msp->i = 2;
    msp->c = 'c';
    msp->f = 2.1f;

    return msp; 
}
