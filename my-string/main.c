#include <stdio.h>
#include "my_string.h"

int main(void)
{
    int diff;

    diff = my_compare_string("hello", "HELL");
    printf("hello to HELL: %d\n", diff);

    diff = my_compare_string("hello", "yellow");
    printf("hello to yellow: %d\n", diff);

    diff = my_compare_string("hello", "HELLO");
    printf("hello to HELLO: %d\n", diff);

    return 0;
}
