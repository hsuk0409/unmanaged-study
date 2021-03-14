#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    size_t s_index;
    size_t e_index;
} pts_t;

size_t get_matching_pts(pts_t* ptses, const char* str);

size_t get_matching_pts(pts_t* ptses, const char* str)
{
    pts_t tmp_pts;
    char tmp_str[2096];
    size_t result = 0;
    size_t pts_index = 0;
    char* p = (char*)str;
    size_t str_len = strlen(str);
    int i;
    int k;
    
    strcpy(tmp_str, p);
    for (i = 0; i < (int)str_len; ++i) {
        if (p[i] == ')') {
            printf("end index: %d\n", i);
            for (k = i - 1; k >= 0; --k) {
                if (p[k] != '\0' && p[k] == '(') {
                    printf("start index: %d\n", k);

                    tmp_pts.s_index = (size_t)k;
                    tmp_pts.e_index = (size_t)i;
                    printf("temp pts start index: %d\n", tmp_pts.s_index);
                    printf("temp pts end index: %d\n", tmp_pts.e_index);

                    ptses[pts_index++] = tmp_pts;
                    printf("ptses start index: %d\n", ptses[pts_index - 1].s_index);
                    printf("ptses end index: %d\n", ptses[pts_index - 1].e_index);
                    
                    tmp_str[k] = '\0';
                    tmp_str[i] = '\0';
                    printf("temp start str: %c\n", tmp_str[k]);
                    printf("temp end str: %c\n", tmp_str[i]);

                    p = tmp_str;
                    printf("After strncpy str: %s\n", str);

                    ++result;
                    break;
                }
            } 
        }
    }
    
    return result;
}

int main(void)
{
    {
        pts_t parentheses[50];
        size_t len = get_matching_pts(parentheses, "(({()))}");

        printf("Second test case result: %d\n", len);
        assert(len == 3);

        assert(parentheses[0].s_index == 3);
        assert(parentheses[0].e_index == 4);

        assert(parentheses[1].s_index == 1);
        assert(parentheses[1].e_index == 5);

        assert(parentheses[2].s_index == 0);
        assert(parentheses[2].e_index == 6);
    }

    return 0;
}
