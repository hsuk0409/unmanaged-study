#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char** tokenize_malloc(char* str, const char* delims);

char** tokenize_malloc(char* str, const char* delims)
{
    char** result_pp;
    char tmp_str[4096];
    char* tmp_p;
    size_t i = 0;
    
    printf("[func] str: %s\n", str);
    strncpy(tmp_str, str, strlen(str));
    
    result_pp = malloc(sizeof(char*) * strlen(str));
    tmp_p = strtok(tmp_str, delims);
    while (tmp_p != NULL) {
        /* result_pp = malloc(sizeof(char*)); */
        result_pp[i] = malloc(strlen(tmp_p) + 1);
        strncpy(result_pp[i++], tmp_p, strlen(tmp_p) + 1);
        printf("[func] token pointer: %s\n", result_pp[i - 1]);
        /* result_pp = realloc(result_pp, sizeof(char*) * i); */
        tmp_p = strtok(NULL, delims);
    }
    result_pp[i] = NULL;
    printf("[func end] last token: %s\n", *result_pp);
    
    return result_pp;
}

int main(void)
{
    char** token;
    char** tt;
    char str[] = "Hello, justin! haha!";
    
    token = tokenize_malloc(str, " ");
    tt = token;

    assert(strcmp(*tt++, "Hello,") == 0);
    assert(strcmp(*tt++, "justin!") == 0);
    assert(strcmp(*tt++, "haha!") == 0);

    {
        size_t i;
        tt = token;
        for (i = 0; *tt != NULL; ++i) {
            printf("token%d: %s\n", i, *tt++);
        }
    }
    
    tt = token;

    printf("pre free token: %s\n", *tt);
    while (*tt != NULL) {
        printf("free toekn: %s\n", *tt);
        free(*tt++);
        printf("post free toekn: %s\n", *tt);
    }
    printf("finish free tt!!\n");
    free(token);
    
    return 0;
}
