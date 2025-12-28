/*
 * File Name   : 01_reverse_iterative.c
 * Folder      : LinkedList/02_Intermediate_Linked_List_Programs
 *
 * Description :
 *   Reverse Iterative
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
void reverse_iterative(void);

/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Reverse Iterative");

    return 0;
}

void reverse_iterative(void)
{
    nodePtr prev = NULL;
    nodePtr current = head;
    nodePtr next = NULL;

    while (current != NULL)
    {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current;       // Move pointers one position ahead
        current = next;
    }
    head = prev; // Update head to new first node
}