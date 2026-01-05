/*
 * File Name   : 43_linked_list.c
 * Folder      : 05_advanced
 *
 * Program Name:
 *   43 linked list
 *
 * Description :
 *   TODO: Add description
 *
 * Requirement :
 *   - C Compiler (gcc)
 *   - gcc 43_linked_list.c -o 43_linked_list
 *
 * Author      : Pravin Jogdand
 * Date        : 2025
 *
 * Interview Tags :
 *   - structures
 */

#include <stdio.h>
#include <stdlib.h>

/* Structure Definition */
typedef struct node
{
    int data;
    struct node *next;
} node_t;

/* Pointer to structure */
node_t *head;

/* Function Prototype */
void linked_list(void);
void print_linked_list(void);
/* Main Function */
int main(void)
{
    linked_list();
    print_linked_list();
    return 0;
}

/* Function Definition */
void linked_list(void)
{
    int A[] = {1,2,3,4,5};
    
    node_t *p;
    for(int i=0;i<sizeof(A)/sizeof(A[0]) ;i++)
    {
        node_t *temp = (node_t*)malloc(sizeof(node_t));
        temp->data = A[i];
        temp->next = NULL;
               
        if(i==0 || head==NULL)
        {
            // this is first node
            head = temp;
            p = head;
        }
        else
        {
            p->next = temp;
            p = temp;
        }
    }
}

void print_linked_list(void)
{
    node_t *p = head;
    while(p != NULL)
    {
        printf("data = %d\n", p->data);
        p = p->next;
    }   
}