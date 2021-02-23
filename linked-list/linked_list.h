#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node {
    int value;
    node_t* next;
} node_t;

void print_node(const node_t* head);
void destroy(node_t* head);

#endif
