#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct node {
    char* key;
    int value;
    struct node* next;
} node_t;

typedef struct hashmap {
    node_t** plist;
    size_t length;
} hashmap_t;

#endif
