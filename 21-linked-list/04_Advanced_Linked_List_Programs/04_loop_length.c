/*
 * File Name   : 04_loop_length.c
 * Folder      : LinkedList/04_Advanced_Linked_List_Programs
 *
 * Description :
 *   Loop Length
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
void loop_length(void)
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

    /* Calculate the length of the loop */
    int loop_length = 1;
    fast_ptr = fast_ptr->next;
    while (slow_ptr != fast_ptr)
    {
        fast_ptr = fast_ptr->next;
        loop_length++;
    }

    printf("Length of the loop is: %d\n", loop_length);
}

/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Loop Length");

    return 0;
}
