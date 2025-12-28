/*
 * File Name   : 01_detect_loop.c
 * Folder      : LinkedList/04_Advanced_Linked_List_Programs
 *
 * Description :
 *   Detect Loop
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
void detect_loop(void)
{
    nodePtr slow_ptr = head;
    nodePtr fast_ptr = head;

    while (slow_ptr && fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if (slow_ptr == fast_ptr)
        {
            printf("Loop detected in the linked list.\n");
            return;
        }
    }

    printf("No loop detected in the linked list.\n");
}

/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Detect Loop");

    return 0;
}
