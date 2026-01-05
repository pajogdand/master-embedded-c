/*
 * File Name   : 12_struct_with_string.c
 * Folder      : 01_basic
 *
 * Program Name:
 *   12 struct with string
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 12_struct_with_string.c -o 12_struct_with_string
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 */

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure Definition */
typedef struct
{
    char  *str;
} my_struct;

/* Pointer to structure */
my_struct *p_my_struct;

/* Function Prototype */
void struct_with_string(void);

/* Main Function */
int main(void)
{
    struct_with_string();
    return 0;
}

/* Function Definition */
void struct_with_string(void)
{
    
    my_struct s;

    s.str = "something";
    printf("String = %s\n", s.str);

    s.str = (char *)malloc(30);
    if (!s.str)
        return;

    strcpy(s.str, "EmbeddedC");

    printf("String = %s\n", s.str);

    free(s.str);


    
    
}
