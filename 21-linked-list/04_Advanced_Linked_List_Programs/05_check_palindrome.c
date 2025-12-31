/*
 * File Name   : 05_check_palindrome.c
 * Folder      : LinkedList/04_Advanced_Linked_List_Programs
 *
 * Description :
 *   Check Palindrome
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
void check_palindrome(void)
{
    nodePtr slow_ptr = head;
    nodePtr fast_ptr = head;

    /* First, find the middle of the linked list */
    while (fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    /* Reverse the second half of the linked list */
    nodePtr prev_ptr = NULL;
    nodePtr current_ptr = slow_ptr;
    nodePtr next_ptr = NULL;

    while (current_ptr)
    {
        next_ptr = current_ptr->next;
        current_ptr->next = prev_ptr;
        prev_ptr = current_ptr;
        current_ptr = next_ptr;
    }

    /* Compare the first half and the reversed second half */
    nodePtr first_half_ptr = head;
    nodePtr second_half_ptr = prev_ptr;

    int is_palindrome = 1;
    while (second_half_ptr)
    {
        if (first_half_ptr->data != second_half_ptr->data)
        {
            is_palindrome = 0;
            break;
        }
        first_half_ptr = first_half_ptr->next;
        second_half_ptr = second_half_ptr->next;
    }

    if (is_palindrome)
    {
        printf("The linked list is a palindrome.\n");
    }
    else
    {
        printf("The linked list is not a palindrome.\n");
    }
}

/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Check Palindrome");

    return 0;
}
