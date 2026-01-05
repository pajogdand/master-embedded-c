/*
 * File Name   : 32_self_referential.c
 * Folder      : 03_pointers
 *
 * Program Name:
 *   Self Referential Structure
 *
 * Description :
 *   Demonstrates usage of self-referential structure,
 *   commonly used in linked lists.
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 32_self_referential.c -o 32_self_referential
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 *   - pointers
 *   - linked list
 */

#include <stdio.h>
#include <stdlib.h>

/* Self-referential Structure Definition */
typedef struct my_struct
{
    int i;
    char c;
    float f;
    struct my_struct *next;   /* Pointer to same structure */
} my_struct;

/* Function Prototype */
void self_referential(void);

/* Main Function */
int main(void)
{
    self_referential();
    return 0;
}

/* Function Definition */
void self_referential(void)
{
    /* Create first node */
    my_struct node1;
    node1.i = 10;
    node1.c = 'A';
    node1.f = 1.1f;

    /* Create second node */
    my_struct node2;
    node2.i = 20;
    node2.c = 'B';
    node2.f = 2.2f;

    /* Link nodes */
    node1.next = &node2;
    node2.next = NULL;

    /* Traverse like a linked list */
    my_struct *temp = &node1;

    while (temp != NULL)
    {
        printf("i = %d, c = %c, f = %.2f\n",
               temp->i, temp->c, temp->f);
        temp = temp->next;
    }
}
