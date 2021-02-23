#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

void print_node(const node_t* head)
{
    node_t* p;

    p = head;
    while (p != NULL) {
        printf("%d, ", p->value);
        p = p->next;
    }
}

void destroy(node_t* head)
{
    node_t* p = head;

    while (p != NULL) {
        node_t* next = p->next;
        free(p);
        p = next;
    }
}
