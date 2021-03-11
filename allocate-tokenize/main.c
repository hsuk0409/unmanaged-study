#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char** tokenize_malloc(const char* str, const char* delims);

char** tokenize_malloc(const char* str, const char* delims)
{
    char** result_pp;
    char** tmp_pp;
    char* tmp_str;
    char* token;
    size_t str_len = strlen(str);
    size_t ret_size = 5;
    size_t i = 0;
    
    printf("[func] str: %s\n", str);
    tmp_str = malloc((str_len + 1) * sizeof(char));
    strcpy(tmp_str, str);
    
    result_pp = malloc(sizeof(char*) * ret_size);

    token = strtok(tmp_str, delims);
    while (token != NULL) {
        if (i == ret_size - 1) {
            ret_size += 5;
            tmp_pp = realloc(result_pp, sizeof(char*) * ret_size);
            if (tmp_pp != NULL) {
                result_pp = tmp_pp;
            }
        }
        result_pp[i] = malloc(strlen(token) + 1);
        strcpy(result_pp[i++], token);
        printf("[func] token pointer: %s\n", result_pp[i - 1]);
        token = strtok(NULL, delims);
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
