#include<stdio.h>
#include "select_sort.h"

int main(void)
{
    int nums[10] = { 6, 4, 10, 22, 1, 3, 15 };
    select_sort(nums);
    
    return 0;
}
