/*
 * File Name   : 14_check_empty_list.c
 * Folder      : LinkedList/01_Basic_Linked_List_Programs
 *
 * Description :
 *   Check Empty List
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
int check_empty_list(void);

/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Check Empty List");
    if (check_empty_list())
    {
        printf("The linked list is empty.\n");
    }
    else
    {
        printf("The linked list is not empty.\n");
    }
    return 0;
}

int check_empty_list(void)
{
    return (head == NULL);
}