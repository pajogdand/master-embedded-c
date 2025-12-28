/*
 * File Name   : 02_insert_doubly.c
 * Folder      : LinkedList/03_Doubly_Circular_Linked_List_Programs
 *
 * Description :
 *   Insert Doubly
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
    struct node *prev;
    struct node *next;
} node;

typedef node* nodePtr;

/* ---------- Global Head Pointer ---------- */
nodePtr head = NULL;
nodePtr tail = NULL;
/* ---------- Function Prototypes ---------- */
void insert_doubly(int data);
void print_all_nodes();
/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Insert Doubly");
    insert_doubly(10);
    insert_doubly(20);
    insert_doubly(30);
    insert_doubly(40);

    print_all_nodes();
    return 0;
}

void insert_doubly(int data)
{
    nodePtr newNode = (nodePtr)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void print_all_nodes()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    nodePtr current = head;
    while(current != NULL)
    {
        printf("Node Data: %d\n", current->data);
        current = current->next;
    }
}