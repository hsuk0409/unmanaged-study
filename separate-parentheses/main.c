#include <stdio.h>
#include <assert.h>

#include "separate_parentheses.h"

int main(void)
{
    {
        pts_t parentheses[50];
        size_t len = get_matching_pts(parentheses, "(({()))}");

        printf("111Second test case result: %d\n", len);
        assert(len == 3);

        assert(parentheses[0].s_index == 3);
        assert(parentheses[0].e_index == 4);

        assert(parentheses[1].s_index == 1);
        assert(parentheses[1].e_index == 5);

        assert(parentheses[2].s_index == 0);
        assert(parentheses[2].e_index == 6);
    }

    {
        pts_t parentheses[50];
        size_t len = match_parentheses(parentheses, "(({()))}");

        printf("222Second test case result: %d\n", len);
        assert(len == 3);

        assert(parentheses[0].s_index == 0);
        assert(parentheses[0].e_index == 6);

        assert(parentheses[1].s_index == 1);
        assert(parentheses[1].e_index == 5);

        assert(parentheses[2].s_index == 3);
        assert(parentheses[2].e_index == 4);
    }

    return 0;
}
