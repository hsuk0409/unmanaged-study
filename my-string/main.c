#include <stdio.h>
#include "my_compare_string.h"
#include "my_buffered_print.h"

int main(void)
{
    /* my_compare_string test */
    int diff;

    diff = my_compare_string("hello", "HELL");
    printf("hello to HELL: %d\n", diff);

    diff = my_compare_string("hello", "yellow");
    printf("hello to yellow: %d\n", diff);

    diff = my_compare_string("hello", "HELLO");
    printf("hello to HELLO: %d\n\n\n", diff);

    /* my_buffered_print test */
    buffered_print("Hello, ");
    buffered_print("Justin!. ");
    buffered_print("C is awesome! ");
    buffered_print("C# is awesome too! ");
    buffered_print("Is Java better? ");
    
    return 0;
}
