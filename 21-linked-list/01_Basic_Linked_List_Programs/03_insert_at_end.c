/*
 * File Name   : 03_insert_at_end.c
 * Folder      : LinkedList/01_Basic_Linked_List_Programs
 *
 * Description :
 *   Insert At End
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
    printf("Program: %s\n", "Insert At End");

    return 0;
}
