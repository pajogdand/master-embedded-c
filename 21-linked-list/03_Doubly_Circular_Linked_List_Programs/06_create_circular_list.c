/*
 * File Name   : 06_create_circular_list.c
 * Folder      : LinkedList/03_Doubly_Circular_Linked_List_Programs
 *
 * Description :
 *   Create Circular List
 *
 * Author      : Pravin Jogdand
 * Date        : 25-12-2025
 *
 * Notes       :
 *   - Embedded C friendly
 *   - Dynamic memory using malloc (can be replaced with static pool)
 */

#include <stdio.h>
#include <stdlib.h>

/* ---------- Linked List Node Definition ---------- */
typedef struct node
{
    int data;
    struct node *next;
} node;

typedef node* nodePtr;

/* ---------- Global Head Pointer ---------- */
nodePtr head = NULL;

/* ---------- Function Prototypes ---------- */


/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Create Circular List");

    return 0;
}
