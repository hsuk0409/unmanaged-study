#ifndef REVERSE_STR_STUDY
#define REVERSE_STR_STUDY

void my_reverse_str(char* str);

void my_reverse_str(char* str)
{
    char* start_p = str;
    char* end_p = str + strlen(str) - 1;

    while (start_p < end_p) {
        char tmp = *start_p;
        *start_p = *end_p;
        *end_p = tmp;

        ++start_p;
        --end_p;
    }
}

#endif
