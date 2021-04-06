#include <stdio.h>

int main(void)
{
    {
        size_t x = 11;
        size_t y = 10;
        size_t result;

        result = x + ~y + 1;
        printf("%d\n", result);
    }

    return 0;
}
