#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node node_t;

typedef struct node {
    int value;
    node_t* next;
} node_t;

void print_node(const node_t* head);
void destroy(node_t* head);
void insert_front(node_t** phead, int val);
void insert_sorted(node_t** phead, int val);
void my_remove(node_t** phead, int val);

#endif
