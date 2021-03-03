#include <stdio.h>
#include <string.h>

#include "my_compare_string.h"
#include "my_buffered_print.h"

void reverse_str_use_pointer(char* str);

void reverse_str_use_pointer(char* str)
{
    char* start_p = str;
    char* end_p = str + strlen(str) - 1;

    while (start_p < end_p) {
        char tmp = *start_p;
        *start_p = *end_p;
        *end_p = tmp;

        start_p++;
        end_p--;
    }
}

int main(void)
{

    {
        char str[] = "My name is justin!";
        reverse_str_use_pointer(str);
        printf("reversed str: %s\n", str);
    }

    {
        /* my_compare_string test */
        int diff;

        diff = my_compare_string("hello", "HELL");
        printf("hello to HELL: %d\n", diff);

        diff = my_compare_string("hello", "yellow");
        printf("hello to yellow: %d\n", diff);

        diff = my_compare_string("hello", "HELLO");
        printf("hello to HELLO: %d\n\n\n", diff);
    }

    {
        char str[] = "Hi, my name is justin!";
        char* token;
        
        token = strtok(str, ", ");
        while (token != NULL) {
            printf("token: %s\n", token);
            token = strtok(NULL, ", !");
        }
        puts("");
    }

    /* my_buffered_print test */
    buffered_print("Hello, ");
    buffered_print("Justin!. ");
    buffered_print("C is awesome! ");
    buffered_print("C# is awesome too! ");
    buffered_print("Is Java better? ");

    return 0;
}
