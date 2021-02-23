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

/* 맨 앞에 삽입하는 */
void insert_front(node_t** phead, int val)
{
    node_t* new_node;

    new_node = malloc(sizeof(node_t));
    new_node->value = val;

    /* 맨 앞에 삽입하기 때문에 머리가 새로운 노드를 가르키도록 설정 */
    new_node->next = *phead;
    *phead = new_node;
}

/* 오름차순으로 정렬해서 삽입*/
void insert_sorted(node_t** phead, int val)
{
    node_t** pp;
    node_t* new_node;

    new_node = malloc(sizeof(node_t));
    new_node->value = val;

    /* 후에 phead를 사용하진 않고 그냥 pp로 대체함 */
    pp = phead;
    while (*pp != NULL) {
        if ((*pp)->value >= val) {
            break;
        }
        pp = &(*pp)->next;
    }
    new_node->next = *pp;
    *pp = new_node;
}
