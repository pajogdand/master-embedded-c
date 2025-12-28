/*
 * File Name   : 10_search_element.c
 * Folder      : LinkedList/01_Basic_Linked_List_Programs
 *
 * Description :
 *   Search Element
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
void search_element(int value);

/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Search Element");

    return 0;
}

void search_element(int value)
{
    nodePtr p;
    int position = 1;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    p = head;
    while (p != NULL)
    {
        if (p->data == value)
        {
            printf("Element %d found at position %d.\n", value, position);
            return;
        }
        p = p->next;
        position++;
    }
    printf("Element %d not found in the list.\n", value);
}