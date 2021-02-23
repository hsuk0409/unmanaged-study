#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void print_node(const node_t* head)
{
    node_t* p;

    p = (node_t*)head;
    while (p != NULL) {
        printf("%d, ", p->value);
        p = p->next;
    }
    printf("\n");
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

/* 맨 앞에 삽입하는 코드 */
void insert_front(node_t** phead, int val)
{
    node_t* new_node;

    new_node = malloc(sizeof(node_t));
    new_node->value = val;

    /* 맨 앞에 삽입하기 때문에 머리가 새로운 노드를 가르키도록 설정 */
    new_node->next = *phead;
    *phead = new_node;
}
