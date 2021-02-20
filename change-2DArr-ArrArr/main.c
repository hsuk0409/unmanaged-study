#include <stdio.h>

int main(void)
{
    const int nums[3][5] = {
        { 1, 2, 3, 4, 5 },
        { 1, 2, 3, 4, 5 },
        { 1, 2, 3, 4, 5 }
    };
    const int* nums2[3];

    nums2[0] = nums[0];
    nums2[1] = nums[1];
    nums2[2] = nums[2];

    printf("Origin nums[0] address: %p, nums2[0] address: %p\n", (void*)nums[0], (void*)nums2[0]);
    printf("Add addr nums[0] address: %p, nums2[0] address: %p\n\n", (void*)&nums[0], (void*)&nums2[0]);
    printf("Origin nums[1] address: %p, nums2[1] address: %p\n", (void*)nums[1], (void*)nums2[1]);
    printf("Add addr nums[1] address: %p, nums2[1] address: %p\n\n", (void*)&nums[1], (void*)&nums2[1]);
    printf("Origin nums[2] address: %p, nums2[2] address: %p\n", (void*)nums[2], (void*)nums2[2]);
    printf("Add addr nums[2] address: %p, nums2[2] address: %p\n\n", (void*)&nums[2], (void*)&nums2[2]);

    printf("nums[2]'s offset from nums[0]: %d\n", nums[2] - nums[0]);
    printf("nums[1]'s offset from nums[0]: %d\n", nums[1] - nums[0]);

    printf("\n");
    
    printf("nums2[2]'s offset from nums2[0]: %d\n", &nums2[2] - &nums2[0]);
    printf("nums2[1]'s offset from nums2[0]: %d\n", &nums2[1] - &nums2[0]);    

    return 0;
}
