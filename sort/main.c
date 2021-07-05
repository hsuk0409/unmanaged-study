#include<stdio.h>
#include "select_sort.h"

#define ARR_SIZE (7)

void printArr(int* arr);

int main(void)
{
    int nums[ARR_SIZE] = { 6, 4, 10, 22, 1, 3, 15 };
    
    printf("Before sort!\n");
    printArr(nums);
    
    select_sort(nums, ARR_SIZE);
    
    printf("After sort!\n");
    printArr(nums);
    
    return 0;
}

void printArr(int* arr)
{
    int* tmp = arr;
    int i;
    
    for(i = 0; i < ARR_SIZE; ++i) {
        printf("%d ", tmp[i]);
    }
    printf("\n");
}
