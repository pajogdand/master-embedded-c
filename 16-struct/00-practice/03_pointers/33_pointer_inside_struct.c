/*
 * File Name   : 33_pointer_inside_struct.c
 * Folder      : 03_pointers
 *
 * Program Name:
 *   Pointer Inside Structure
 *
 * Description :
 *   Demonstrates how a structure can contain
 *   a pointer member and how memory is accessed
 *   through it.
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 33_pointer_inside_struct.c -o 33_pointer_inside_struct
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 *   - pointers
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int i;   /* Pointer member */
} my_normal_struct;


/* Structure Definition */
typedef struct
{
    int *i;   /* Pointer member */
} my_struct;


/* Structure Definition */
typedef struct
{
    char *str;   /* Pointer member */
} my_str_struct;
/* Pointer to structure */
my_struct *p_my_struct;

/* Function Prototype */
void normal_variable_struct(void);
void pointer_inside_struct(void);
void string_inside_struct(void);

/* Main Function */
int main(void)
{
    // pointer_inside_struct();
    // string_inside_struct();
    normal_variable_struct();
    return 0;
}


void normal_variable_struct(void)
{
    int value = 100;
    my_normal_struct s;
    s.i = value;

    my_normal_struct s1 = s;
           
    printf("s.i = %d\n", s.i);
    printf("s1.i = %d\n", s1.i);

    s1.i = 200;
    printf("s.i = %d\n", s.i);
    printf("s1.i = %d\n", s1.i);   


}
/* Function Definition */
void pointer_inside_struct(void)
{
    int value = 100;
    my_struct s;    
    /* Assign address of variable to pointer inside struct */
    s.i = &value;
    /* Assign structure pointer */
    p_my_struct = &s;
    /* Access value through structure pointer */
    printf("Value = %d\n", *(p_my_struct->i));
    /* Modify value using pointer inside structure */
    *(p_my_struct->i) = 200;
    printf("Modified Value = %d\n", *(p_my_struct->i) );

    my_struct s1 = s;
    printf("s.value=%d , s1.value = %d\n", *(s.i) , *(s1.i));

    s1.i =(int*)malloc(sizeof(int));
    *(s1.i) = 300;
    printf("s.value=%d , s1.value = %d\n", *(s.i) , *(s1.i));
    p_my_struct = &s1;
    /* Access value through structure pointer */
    printf("Value = %d\n", *(p_my_struct->i));
   
}

void string_inside_struct(void)
{
    my_str_struct s = {"something"};
    printf("s.str = %s\n" , s.str);
    
    my_str_struct s1 = s;
    printf("s1.str = %s\n" , s1.str);

    s1.str = (char*)malloc(sizeof(100));
    strcpy(s1.str,"nothing");
    printf("updated s.str = %s\n" , s.str);
    printf("updated s1.str = %s\n" , s1.str);
}
