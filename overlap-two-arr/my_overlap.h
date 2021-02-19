#ifndef MY_OVERLAP_H
#define MY_OVERLAP_H

#define TRUE (1)
#define FALSE (0)

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

int is_my_overlap(int nums1[], const size_t length1, int num2[], const size_t length2);

#endif
