/*
 * File Name   : 03_delete_doubly.c
 * Folder      : LinkedList/03_Doubly_Circular_Linked_List_Programs
 *
 * Description :
 *   Delete Doubly
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
void deleteDoubly(int position);
void CreateDoublyLinkedList(void);
void DisplayDoubleLiskedList(void)
/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Delete Doubly");
    CreateDoublyLinkedList();
    printf("Original List: ");
    DisplayDoubleLiskedList();
    int position = 2; // Example position to delete
    deleteDoubly(position);
    printf("List after deletion at position %d: ", position);
    DisplayDoubleLiskedList();
    return 0;
}

void CreateDoublyLinkedList(void)
{
    // Creating a sample doubly circular linked list with 5 nodes
    for (int i = 1; i <= 5; i++)
    {
        nodePtr newNode = (nodePtr)malloc(sizeof(node));
        newNode->data = i;
        newNode->next = NULL;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            newNode->next = NULL;
        }
        else
        {
            nodePtr temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }
}

void deleteDoubly(int position)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    nodePtr current = head;
    int count = 0;

    // If head needs to be removed
    if (position == 0)
    {
        // If there's only one node
        if (head->next == head)
        {
            free(head);
            head = NULL;
            return;
        }

        // Find the last node
        nodePtr last = head;
        while (last->next != head)
            last = last->next;

        last->next = head->next;
        nodePtr temp = head;
        head = head->next;
        free(temp);
        return;
    }

    // Traverse to the node before the one to be deleted
    while (count < position - 1 && current->next != head)
    {
        current = current->next;
        count++;
    }

    // If position is more than number of nodes
    if (current->next == head)
    {
        printf("Position out of bounds. Cannot delete.\n");
        return;
    }

    nodePtr temp = current->next;
    current->next = temp->next;
    free(temp);
}