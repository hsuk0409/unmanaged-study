#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_io.h"

int load_document(const char* doc)
{
    char line[4096];
    char* buffer;

    FILE* fp = fopen("hello.txt", "r");
    if (fp == NULL) {
        printf("file is not exist!!\n");
        return FALSE;
    }
    
    printf("%d\n", feof(fp));
    while (!feof(fp)) {
        buffer = fgets(line, sizeof(line), fp);
        printf("%s\n", line);
        printf("%s\n", buffer);
    }
    
    fclose(fp);
    
    return TRUE;
}
