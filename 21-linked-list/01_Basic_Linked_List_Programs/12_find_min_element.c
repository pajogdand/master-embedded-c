/*
 * File Name   : 12_find_min_element.c
 * Folder      : LinkedList/01_Basic_Linked_List_Programs
 *
 * Description :
 *   Find Min Element
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

void find_min_element(void);
/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Find Min Element");
    find_min_element();
    return 0;
}

void find_min_element(void)
{
    nodePtr p;
    int min;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    p = head;
    min = p->data; // Initialize min with the first node's data

    while (p != NULL)
    {
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }

    printf("Minimum element in the linked list: %d\n", min);
}