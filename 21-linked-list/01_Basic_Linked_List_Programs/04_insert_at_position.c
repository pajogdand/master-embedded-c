/*
 * File Name   : 04_insert_at_position.c
 * Folder      : LinkedList/01_Basic_Linked_List_Programs
 *
 * Description :
 *   Insert At Position
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

void insert_at_position(int data, int position);
/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Insert At Position");

    return 0;
}

void insert_at_position(int data, int position)
{
    nodePtr new_node, p;
    int k = 1;

    new_node = (nodePtr)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    
    // insert at position
    if (position == 1)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        p = head;
        while (p != NULL && k < position - 1)
        {
            p = p->next;
            k++;
        }
        if (p == NULL)
        {
            printf("Position out of bounds\n");
            free(new_node);
        }
        else
        {
            new_node->next = p->next;
            p->next = new_node;
        }
    }
}