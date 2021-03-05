#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char** tokenize_malloc(char* str, const char* delims);

char** tokenize_malloc(char* str, const char* delims)
{
    char** tmp_pp;
    char** result_pp;
    char tmp_str[4096];
    char* tmp_p;
    size_t i = 0;
    
    printf("[func] str: %s\n", str);
    strncpy(tmp_str, str, strlen(str));
    
    tmp_p = strtok(tmp_str, delims);
    while (tmp_p != NULL) {
        tmp_pp = malloc(sizeof(char*));
        tmp_pp[i] = malloc(strlen(tmp_p) + 1);
        tmp_pp[i++] = tmp_p;
        printf("[func] token pointer: %s\n", tmp_pp[i - 1]);
        result_pp = realloc(tmp_pp, sizeof(char*) * i);
        tmp_p = strtok(NULL, delims);
    }
    printf("[func end] last token: %s\n", *result_pp);
    
    return result_pp;
}

int main(void)
{
    char** token;
    char** tt;
    char str[] = "Hello, justin! haha!";
    
    token = tokenize_malloc(str, ",!");
    tt = token;

    printf("token: %s\n", *tt);
    assert(strcmp(*tt++, "Hello") == 0);
    
    tt = token;
    while (*tt != NULL) {
        free(tt++);
    }
    free(token);
    
    return 0;
}
