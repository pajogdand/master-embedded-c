/*
 * File Name   : 10_copy_struct.c
 * Folder      : 01_basic
 *
 * Program Name:
 *   Copy structure
 *
 * Description :
 *   Demonstrates copying one structure to another using
 *   direct assignment.
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 10_copy_struct.c -o 10_copy_struct
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Structure Definition */
typedef struct
{
    int   i;
    char  c;
    float f;
} my_struct;

typedef struct
{
    int   i;
    char* str;
    float f;
} my_str_struct;

typedef struct
{
    int   i;
    char str_array[10];
    float f;
} my_array_struct;

/* Function Prototype */
void copy_struct(my_struct * , my_struct);

/* Main Function */
int main(void)
{
    my_struct src = {100, 'P', 3.14f};
    my_struct local_dest = src;
    printf("i = %d , c = %c , f = %f \n" , local_dest.i , local_dest.c, local_dest.f);

    // my_str_struct str_src = {100 , "something" , 3.14f};
    // my_str_struct str_dest = str_src;
    // printf("i = %d , c = %s , f = %f \n" , str_dest.i , str_dest.str, str_dest.f);

    // my_str_struct str_src;
    // str_src.i = 100l;
    // str_src.str = "something";
    // str_src.f =3.14f;
    // my_str_struct str_dest = str_src;
    // printf("i = %d , c = %s , f = %f \n" , str_dest.i , str_dest.str, str_dest.f);

    // my_str_struct str_src;
    // str_src.i = 100l;
    // str_src.str = (char *)malloc(sizeof("something")+1);
    // strcpy(str_src.str ,"something");
    // str_src.f =3.14f;
    // my_str_struct str_dest = str_src;
    // printf("i = %d , c = %s , f = %f \n" , str_dest.i , str_dest.str, str_dest.f);

    my_array_struct array_src;
    array_src.i = 100;
    strcpy(array_src.str_array ,"something");
    array_src.f =3.14f;
    my_array_struct str_dest = array_src;
    printf("i = %d , c = %s , f = %f \n" , str_dest.i , str_dest.str_array, str_dest.f);


    my_struct dest;
    copy_struct(&dest ,src);
    printf("i = %d , c = %c , f = %f \n" , dest.c , dest.c, dest.f);
    return 0;
}

/* Function Definition */
void copy_struct(my_struct *dest ,my_struct src)
{
    dest->i = src.i;
    dest->c = src.c;
    dest->f = src.f; 

}
