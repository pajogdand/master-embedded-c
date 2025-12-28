/*
 * File Name   : 01_create_doubly_linked_list.c
 * Folder      : LinkedList/03_Doubly_Circular_Linked_List_Programs
 *
 * Description :
 *   Create Doubly Linked List
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
    struct node *prev;
} node;

typedef node* nodePtr;

/* ---------- Global Head Pointer ---------- */
nodePtr head = NULL;
nodePtr tail = NULL;

/* ---------- Function Prototypes ---------- */


void create_doubly_linked_list(nodePtr* head, int data);
/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Create Doubly Linked List");

    create_doubly_linked_list(&head, 10);
    create_doubly_linked_list(&head, 20);
    create_doubly_linked_list(&head, 30);
    create_doubly_linked_list(&head, 40);
    return 0;
}

void create_doubly_linked_list(nodePtr* head, int data)
{
    nodePtr newNode = (nodePtr)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}    tail = newNode;
    tail = newNode;
}       