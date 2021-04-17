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
