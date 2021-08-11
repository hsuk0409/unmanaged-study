#include<stdio.h>
#include "linked_list.h"

int main(void)
{
    node_t* head = NULL;

    insert_front(&head, 5);
    print_node(head);
    insert_front(&head, 6);
    print_node(head);
    insert_front(&head, 7);
    print_node(head);
    insert_front(&head, 8);
    print_node(head);
    insert_front(&head, 0);
    print_node(head);

    insert_sorted(&head, 2);
    print_node(head);

    my_remove(&head, 6);
    print_node(head);

    destroy(head);
    head = NULL;
}
