/*
 * File Name   : 01_create_singly_linked_list.c
 * Folder      : LinkedList/01_Basic_Linked_List_Programs
 *
 * Description :
 *   Create Singly Linked List
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


/* ---------- Main Function ---------- */
int main(void)
{
    printf("Program: %s\n", "Create Singly Linked List");
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    return 0;
}
