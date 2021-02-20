#include <stdio.h>
#include "my_string.h"

int my_tolower(char ch);

int my_tolower(char ch)
{
    return ch | 0x20;
}

int my_compare_string(const char* str1, const char* str2)
{
    int ch1;
    int ch2;

    ch1 = my_tolower(*str1);
    ch2 = my_tolower(*str2);

    while (*str1 != '\0' && ch1 == ch2) {
        ch1 = my_tolower(*++str1);
        ch2 = my_tolower(*++str2);
    }

    if (ch1 == ch2) {
        return 0;
    }

    return ch1 > ch2 ? 1 : -1;
}
/*
char* my_strcat(char* dest, const char* src)
{
    
}
*/
