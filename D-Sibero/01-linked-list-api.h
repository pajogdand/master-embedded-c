#ifndef linked-list-apt_H_   /* Include guard */
#define linked-list-apt_H_
typedef struct linked_list {
void * data;
struct linked_list * next;
} linked_list_s;

typedef linked_list_s* linked_list_sp;

//head of linked list
linked_list_sp head;

// Define the header file specifications for:

// 1. Add a node at the beginning of the list
void add_node_at_beginning(void *data);
// 2. Add a node at the end of the list
void add_node_at_end(void *data);
// 3. Remove a node
void remove_node(linked_list_sp node_to_remove);
// 4. Return the count of the nodes
int get_count_of_nodes();

#endif