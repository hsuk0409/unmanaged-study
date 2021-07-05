#ifndef SELECT_SORT_H
#define SELECT_SORT_H

#include <stdio.h>

void select_sort(int* nums, size_t length);

size_t get_min_index(int* nums, size_t start, size_t length);

void select_sort(int* nums, size_t length)
{
    int* tmp_p = nums;
    size_t i;
    size_t min;

    for(i = 0; i < length - 1; ++i) {
        int tmp;
        min = get_min_index(tmp_p, i, length);
        tmp = tmp_p[i];
        tmp_p[i] = tmp_p[min];
        tmp_p[min] = tmp;
    }
}

size_t get_min_index(int* nums, size_t start, size_t length)
{
    size_t i;
    size_t min = start;
    int* tmp = nums;
    for (i = start + 1; i < length; ++i) {
        if(tmp[min] > tmp[i]) {
            min = i;
        }
    }

    return min;
}

#endif
