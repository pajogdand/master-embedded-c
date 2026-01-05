/*
 * File Name   : 07_pass_by_reference.c
 * Folder      : 01_basic
 *
 * Program Name:
 *   07 pass by reference
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 07_pass_by_reference.c -o 07_pass_by_reference
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 */

#include <stdio.h>

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
void pass_by_ref(my_struct* msp);
void pass_by_ptr(my_struct* msp);
void pass_by_ptr_to_ptr(my_struct** mspp);
/* Main Function */
int main(void)
{
    my_struct ms = {1, 'c' , 1.1f};

    //1st method
    printf("Before i = %d , c = %c , f = %f \n" , ms.i , ms.c, ms.f);
    pass_by_ref(&ms);
    printf("After i = %d , c = %c , f = %f \n" , ms.i , ms.c, ms.f);
    
    //2nd method
    printf("========================================================\n");
    printf("Before i = %d , c = %c , f = %f \n" , ms.i , ms.c, ms.f);
    my_struct *ms_local_ptr = &ms;
    pass_by_ptr(ms_local_ptr);
    printf("Before i = %d , c = %c , f = %f \n" , ms.i , ms.c, ms.f);


    printf("========================================================\n");
    printf("Before i = %d , c = %c , f = %f \n" , ms.i , ms.c, ms.f);
    pass_by_ptr_to_ptr(&ms_local_ptr);
    printf("Before i = %d , c = %c , f = %f \n" , ms.i , ms.c, ms.f);

    
    return 0;
}

/* Function Definition */
void pass_by_ref(my_struct* msp)
{
    (*msp).i = 2;
    (*msp).c = 'b';
    (*msp).f = 2.1f;
}

// OR
// void pass_by_ref(my_struct* msp)
// {
//     msp->i = 2;
//     msp->c = 'b';
//     msp->f = 2.1f;
// }

void pass_by_ptr(my_struct* msp)
{
    msp->i = 3;
    msp->c = 'c';
    msp->f = 3.1f;    
}

void pass_by_ptr_to_ptr(my_struct** mspp)
{
    // (*mspp)->i = 3;
    // (*mspp)->c = 'd';
    // (*mspp)->f = 3.1f;

    my_struct *ms_local_p = *mspp;
    ms_local_p->i = 4;
    ms_local_p->c = 'd';
    ms_local_p->f = 4.1f;
}
