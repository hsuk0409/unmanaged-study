#include <stdio.h>
#include <stdlib.h>

#include "separate_parentheses.h"

int compare_start_index(const void* p1, const void* p2);

size_t match_parentheses(pts_t* ptses, const char* str)
{
    pts_t* new_pts = NULL;
    size_t pts_size = 0;

    start_index_t* start_ptses = NULL;
    size_t current_index = 0;

    const char* p = str;
    size_t i;

    while (*p != '\0') {
        if (*p == '(') {
            start_ptses = realloc(start_ptses, (current_index + 1) * sizeof(start_index_t));
            start_ptses[current_index].pts = *p;
            start_ptses[current_index++].index = p - str;
        } else if (*p == ')') {
            for (i = current_index - 1; i != (size_t)-1; --i) {
                if (start_ptses[i].pts == *p - 1) {
                    if (start_ptses[i].index == (size_t)-1) {
                        continue;
                    }
                    
                    new_pts = realloc(new_pts, (pts_size + 1) * sizeof(pts_t));
                    new_pts[pts_size].s_index = start_ptses[i].index;
                    new_pts[pts_size++].e_index = p - str;
                    start_ptses[i].index = (size_t)-1;
                    break;
                }
            }
        }
        ++p;
    }
    qsort(new_pts, pts_size, sizeof(pts_t), compare_start_index);

    for (i = 0; i < pts_size; ++i) {
        ptses[i].s_index = new_pts[i].s_index;
        ptses[i].e_index = new_pts[i].e_index;
    }
    
    free(start_ptses);
    start_ptses = NULL;

    free(new_pts);
    new_pts = NULL;

    return pts_size;
}

int compare_start_index(const void* p1, const void* p2)
{
    const pts_t* pt1 = p1;
    const pts_t* pt2 = p2;

    return pt1->s_index - pt2->s_index;
}

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
