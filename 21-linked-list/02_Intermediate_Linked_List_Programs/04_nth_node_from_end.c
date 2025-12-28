/*
 * File Name   : 04_nth_node_from_end.c
 * Folder      : LinkedList/02_Intermediate_Linked_List_Programs
 *
 * Description :
 *   Nth Node From End
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
void nth_node_from_end(int n);

/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Nth Node From End");

    return 0;
}
