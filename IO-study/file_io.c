#include <stdio.h>
#include <stdlib.h>
#include <string,h>

#include "file_io.h"

int get_file_size(FILE* fp);

int get_file_size(FILE* fp)
{
    int size;
    int curPos = ftell(fp);

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);

    fseek(fp, curPos, SEEK_SET);

    return size;
}

int load_document(const char* doc)
{
    char** pp = NULL;
    char* p;
    char* buffer;
    int file_size;
    size_t pp_len = 0;
    size_t i;

    FILE* fp = fopen("hello.txt", "r");
    
    size = get_file_size(fp);
    buffer = malloc(size + 1);
    memset(buffer, 0, size + 1);

    while (tmp != EOF) {
        
        strncpy(p, tmp, strlen(tmp) + 1)
        pp = realloc(pp, ++pp_len * sizeof(const char*));
        pp[pp_len - 1] = p;
    }

    for(i = 0; i < pp_len; ++i) {
        printf("string in pp: %s\n", pp[i]);
        free(pp[i]);
    }

    free(pp);
    pp = NULL;

    fclose(fp);
    
    return TRUE
}
