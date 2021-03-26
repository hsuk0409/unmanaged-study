#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct my_item {
    const int32_t order;
    const char task[512];
} my_item_t;

typedef struct my_list {
    size_t count;
    my_item_t* item;
} my_list_t;


int main(void)
{
    my_list_t list;
    size_t i;
    
    list.count = 0;
    list.item = malloc(sizeof(my_item_t*) * 15);
    
    printf("count: %d\n", list.count);
    printf("my_item_t pointer size: %d\n", sizeof(my_item_t*));
    printf("my_item_t size: %d\n", sizeof(my_item_t));
    printf("item size: %d\n", sizeof(list.item));
    
    free(list.item);
    
    return 0;
}
