#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t s_index;
    size_t e_index;
} pts_t;

size_t get_matching_pts(pts_t* ptses, const char* str);

size_t get_matching_pts(pts_t* ptses, const char* str)
{
    pts_t tmp_pts;
    size_t result = 0;
    size_t pts_index = 0;
    char* p = (char*)str;
    size_t str_len = strlen(str);
    int i;
    int k;
    
    for (i = 0; i < (int)str_len) {
        if (p[i] == ')') {
            printf("end index: %d\n", i);
            for (k = i - 1; k >= 0; --k) {
                if (p[k] != '\0' && p[k] == '(') {
                    printf("start index: %d\n", k);
                    tmp_pts.s_index = (size_t)k;
                    tmp_ots.e_index = (size_t)i;
                    printf("temp pts start index: %d\n", tmp_pts.s_index);
                    printf("temp pts end index: %d\n", tmp_pts.e_index);
                    ptses[pts_index++] = tmp_pts;
                    
                    
                }
            } 
        }
    }
    
    return result;
}

int main(void)
{
    
    return 0;
}
