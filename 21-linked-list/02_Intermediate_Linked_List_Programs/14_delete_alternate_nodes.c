/*
 * File Name   : 14_delete_alternate_nodes.c
 * Folder      : LinkedList/02_Intermediate_Linked_List_Programs
 *
 * Description :
 *   Delete Alternate Nodes
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

void delete_alternate_nodes(nodePtr head);
/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Delete Alternate Nodes");

    delete_alternate_nodes(head);
    return 0;
}

void delete_alternate_nodes(nodePtr head)
{
    nodePtr current = head;
    nodePtr temp;

    while (current != NULL && current->next != NULL)
    {
        temp = current->next;
        current->next = temp->next;
        free(temp);
        current = current->next;
    }
}