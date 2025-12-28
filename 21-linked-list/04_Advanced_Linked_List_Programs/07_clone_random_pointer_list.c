/*
 * File Name   : 07_clone_random_pointer_list.c
 * Folder      : LinkedList/04_Advanced_Linked_List_Programs
 *
 * Description :
 *   Clone Random Pointer List
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
    printf("Program: %s\n", "Clone Random Pointer List");

    return 0;
}
