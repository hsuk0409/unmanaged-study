#include <stdio.h>
#include "getter_macro.h"

#define MAX(x, y) (x > y ? x : y)

#define MIN(x, y) (x > y ? y : x)

int main(void)
{
    {
        int result = 0;
        int x = 10;
        int y = 20;

        result = MAX(x, y);
        printf("Max: %d\n", result);

        result = MIN(x, y);
        printf("Min: %d\n", result);
    }

    {
        team_t team;
        team.id = 0;
        team.name = "Justin player";
        team.hp = 10002;

        printf("%3d %6d %s\n", get_player_id(&team), get_player_hp(&team), get_player_name(&team));
    }

    return 0;
}
