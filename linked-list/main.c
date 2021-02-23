#include<stdio.h>
#include "linked_list.h"

int main(void)
{
    node_t* head = NULL;

    insert_front(&head, 1);
    print_node(head);
    insert_front(&head, 2);
    print_node(head);
    insert_front(&head, 3);
    print_node(head);
    insert_front(&head, 4);
    print_node(head);

    destroy(head);
    head = NULL;
}
