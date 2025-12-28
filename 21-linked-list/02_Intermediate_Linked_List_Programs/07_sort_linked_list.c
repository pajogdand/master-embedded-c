/*
 * File Name   : 07_sort_linked_list.c
 * Folder      : LinkedList/02_Intermediate_Linked_List_Programs
 *
 * Description :
 *   Sort Linked List
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
void sort_linked_list(void);
void sort_linked_list_using_tdobule_pointer(void);

/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Sort Linked List");
    sort_linked_list();
    return 0;
}

void sort_linked_list(void)
{
    nodePtr i, j;
    int temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                // Swap data
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("Linked list sorted in ascending order.\n");
}
