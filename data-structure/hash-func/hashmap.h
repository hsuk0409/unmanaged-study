#ifndef HASHMAP_H
#define HASHMAP_H

#define TRUE (1)
#define FALSE (0)

typedef struct node {
    char* key;
    int value;
    struct node* next;
} node_t;

typedef struct hashmap {
    node_t** plist;
    size_t length;
} hashmap_t;

hashmap_t* init_hashmap_malloc(size_t length);

int add_key(hashmap_t* hashmap, const char* key, const int value);

int get_value(const hashmap_t* hashmap, const char* key);

int update_value(hashmap_t* hashmap, const char* key, int value);

int remove_key(hashmap_t* hashmap, const char* key);

void destroy(hashmap_t* hashmap);

#endif
