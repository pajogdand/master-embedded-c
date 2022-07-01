#include <stdio.h>
#include <stdlib.h>


typedef struct linked_list {
void * data;
struct linked_list * next;
} linked_list_s;

linked_list_s *first;
// Define the header file specifications for:

// 1. Add a linked_list at the beginning of the list
void add_node_at_beginning(linked_list_s *first , void *data);
// 2. Add a linked_list at the end of the list
void add_node_at_end(void *data);
// 3. Remove a linked_list
void remove_node(linked_list_s *node_to_remove);
// 4. Return the count of the nodes
int get_count_of_nodes(linked_list_s *first);

void create(int A[] , int n)
{
    int i;
    struct linked_list *t,*last;
    for(i=0;i<n;i++)
    {
        if(i == 0)
        {
            // create first linked_list
            first = (struct linked_list *)malloc(sizeof(struct linked_list*));
            first->data = (int *)(&A[i]);
            first->next = NULL;
            
            // make last point of first linked_list
            last  =  first;
        }
        else{
            t = (struct linked_list *)malloc(sizeof(struct linked_list *));
            t->data = (int *)(&A[i]);
            t->next = NULL;

            last->next = t;
            last = t;
        }
    }
    
}

void display()
{
    struct  linked_list *t;
    t = first;

    printf("Printing liked list\n");
    while(t != NULL)
    {

        printf("data = %d " , t->data);
        t = t->next;
    }
}

void add_node_at_beginning(void *data)
{
    linked_list_s *temp = (linked_list_s *)malloc(sizeof(linked_list_s));
    temp->data = data;

    temp->next = first;

    first = temp;
}

int main()
{
     int A[] = {100,5,7,0,8,10};
 
    create(A , 6);

    display();

    int * data = (int *)malloc(sizeof(int));
    add_node_at_beginning(first, data);
    display();

    exit(0);
}
