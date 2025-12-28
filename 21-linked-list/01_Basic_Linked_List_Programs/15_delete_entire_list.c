/*
 * File Name   : 15_delete_entire_list.c
 * Folder      : LinkedList/01_Basic_Linked_List_Programs
 *
 * Description :
 *   Delete Entire List
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
void delete_entire_list(void);

/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Delete Entire List");

    delete_entire_list();
    return 0;
}

void delete_entire_list(void)
{
    nodePtr temp, p;
    p = head;
    while (p != NULL)
    {
        temp = p;
        p = p->next;
        printf("Deleting node with data: %d\n", temp->data);
        free(temp);
    }
    head = NULL; // Set head to NULL after deleting the entire list
    printf("All nodes deleted. The linked list is now empty.\n");
}