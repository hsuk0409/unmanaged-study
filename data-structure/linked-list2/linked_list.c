#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

void print_node(const node_t* head)
{
    node_t* p;
    
    p = (void*)head;
    while (p != NULL) {
        printf("Current value: %d\n", p->value);
        p = p->next;
    }
}

void destroy(node_t* head)
{
    node_t* p = (void*)head;

    while (p != NULL) {
        node_t* next = p->next;
        free(p);
        p = next;
    }
}

void insert_front(node_t** phead, int n)
{
    node_t* new_node;

    new_node = malloc(sizeof(node_t));
    new_node->value = n;

    new_node->next = *phead;
    *phead = new_node;
}

void remove_node(node_t** phead, int val)
{
    node_t** pp;

    pp = phead;
    while (*pp != NULL) {
        if ((*pp)->value == val) {
            node_t* tmp = *pp;
            *pp = (*pp)->next;
            free(tmp);
            break;
        }
        pp = &(*pp)->next;
    }
}
