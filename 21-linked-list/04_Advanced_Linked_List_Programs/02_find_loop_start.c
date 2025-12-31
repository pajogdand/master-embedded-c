/*
 * File Name   : 02_find_loop_start.c
 * Folder      : LinkedList/04_Advanced_Linked_List_Programs
 *
 * Description :
 *   Find Loop Start
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
void find_loop_start(void)
{
    nodePtr slow_ptr = head;
    nodePtr fast_ptr = head;

    /* First, detect if a loop exists using Floyd's Cycle-Finding Algorithm */
    int loop_exists = 0;
    while (slow_ptr && fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if (slow_ptr == fast_ptr)
        {
            loop_exists = 1;
            break;
        }
    }

    if (!loop_exists)
    {
        printf("No loop detected in the linked list.\n");
        return;
    }

    /* Find the starting node of the loop */
    slow_ptr = head;
    while (slow_ptr != fast_ptr)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
    }

    printf("Loop starts at node with data: %d\n", slow_ptr->data);
}

/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Find Loop Start");

    return 0;
}
