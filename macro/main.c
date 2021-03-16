#include <stdio.h>

#define MAX(x, y) (x > y ? x : y)

#define MIN(x, y) (x > y ? y : x)

int main(void)
{
    int result = 0;
    int x = 10;
    int y = 20;

    result = MAX(x, y);
    printf("Max: %d\n", result);

    result = MIN(x, y);
    printf("Min: %d\n", result);

    return 0;
}
