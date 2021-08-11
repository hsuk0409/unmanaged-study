#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashmap.h"

size_t hash_function(const char* key);

size_t hash_function(const char* key)
{
    size_t code = 0;
    const char* c = key;

    while (*c != '\0') {
        code += *c++;
    }
    return code;
}

hashmap_t* init_hashmap_malloc(size_t length)
{
    hashmap_t* hashmap;
    size_t i;
    
    hashmap = (node**)malloc(sizeof(node*) * length);
    hashmap->length = length;
    for (i = 0; i < length; ++i) {
        hashmap->plist[i] = NULL;
    }
    return hashmap;
}
