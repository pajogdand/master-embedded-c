/*
 * File Name   : 02_insert_at_beginning.c
 * Folder      : LinkedList/01_Basic_Linked_List_Programs
 *
 * Description :
 *   Insert At Beginning
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

void insert_at_beginning(int data);
void display_list(void);
void create_singly_linked_list(int arr[], int n);
/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Insert At Beginning");
    int array[] = {10, 20, 30, 40, 50};
    int n = sizeof(array) / sizeof(array[0]);
    create_singly_linked_list(array, n);
    printf("Original List: ");
    display_list(); 
    insert_at_beginning(5);
    printf("After Insertion at Beginning: ");
    display_list();
    return 0;
}

void create_singly_linked_list(int arr[], int n)
{
    nodePtr temp, p;
    int i;

    head = (nodePtr)malloc(sizeof(node));
    if (head == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    head->data = arr[0];
    head->next = NULL;
    p = head;

    for (i = 1; i < n; i++)
    {
        temp = (nodePtr)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
        temp->data = arr[i];
        temp->next = NULL;
        p->next = temp;
        p = temp;
    }
}

void insert_at_beginning(int data)
{
    nodePtr new_node = (nodePtr)malloc(sizeof(node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Inserting node at the beginning with data: %d\n", data);
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}
