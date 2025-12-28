/*
 * File Name   : 13_sum_of_nodes.c
 * Folder      : LinkedList/01_Basic_Linked_List_Programs
 *
 * Description :
 *   Sum Of Nodes
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
void sum_of_nodes(void);

/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Sum Of Nodes");

    return 0;
}

void sum_of_nodes(void)
{
    nodePtr p;
    int sum = 0;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    p = head;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    printf("Sum of all nodes in the linked list: %d\n", sum);
}