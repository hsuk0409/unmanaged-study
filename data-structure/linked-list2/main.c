#include <stdio.h>
#include "linked_list.h"

int main(void)
{
    node_t* head = NULL;
    
    insert_front(&head, 1);
    insert_front(&head, 3);
    insert_front(&head, 5);
    insert_front(&head, 7);
    
    print_node(head);
    
    destroy(head);
    head = NULL;
}
