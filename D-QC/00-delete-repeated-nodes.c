#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
}* head = NULL;

void create_link_list(int *p , int size)
{
    struct node *hp = NULL;
    for(int i=0;i<size ;i++)
    {
        struct  node * t = (struct node *) malloc(sizeof(struct node));
        if(t  == NULL)
        {
            printf("Memory allocation failed\n");
        }       
        t->data = p[i];
        t->next = NULL;        
                        
        if(head == NULL)
        {
            head = t;
            hp = t;                     
        }
        else{
            hp->next = t;
            hp = t;
        }
    }
}
void print_linked_list()
{
    struct node *p = head;
    while(p)
    {
        printf("%d\t" ,p->data);
        p = p->next;
    }
    printf("\n");
}

void condense_list()
{
    int found_duplicate = 0;
    struct node *p = head;
        
    while(p)
    {
        struct node *q = p->next;
        struct node *qt = p;
        while(q)
        {
            if(p->data == q->data)
            {                
                qt->next = q->next;
                free(q);
                q=qt->next;
                continue;
            }
            qt = q;
            q = q->next;
        }        
        p=p->next;
    }
    
}
int main(void)
{
    int A[5] = {3,5,3,3,100};
    create_link_list(A, 5);
    print_linked_list();
    condense_list();
    print_linked_list();

    exit(0);
}