#ifndef SEPARATE_PARENTHESES_H
#define SEPARATE_PARENTHESES_H

typedef struct {
    size_t s_index;
    size_t e_index;
} pts_t;

typedef struct {
    char pts;
    size_t index;
} start_index_t;

size_t get_matching_pts(pts_t* ptses, const char* str);
size_t match_parentheses(pts_t* ptses, const char* str);

#endif
