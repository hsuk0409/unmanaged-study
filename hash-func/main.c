#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "hashmap.h"

size_t hash_int(int value)
{
    return value;
}

size_t hash_float(float value)
{
    return *((size_t*)&value);
}

size_t hash_data(const void* data, size_t length)
{
    const char* p;
    size_t i;
    size_t hash;

    p = data;
    hash = 0;
    for (i = 0; i < length; ++i) {
        hash = 65599 * hash + *p++;
    }

    return hash ^ (hash >> 16);
}

int main(void)
{
    {
        int a = 12345;
        printf("%d\n", hash_int(a));
    }

    {
        float a = 12345.123f;
        printf("%d\n", hash_float(a));
    }

    {
        printf("%u\n", hash_data("Jusin!!", strlen("justin")));
    }

    {
        typedef struct {
            unsigned char age;
            unsigned int id;
            char name[64];
        } employee_t;

        employee_t person;
        memset(&person, 0, sizeof(employee_t));
        person.age = 29;
        person.id = 18274192;
        strcpy(person.name, "justin");
        printf("%d\n", hash_data(&person, sizeof(employee_t)));
    }

    return 0;
}
