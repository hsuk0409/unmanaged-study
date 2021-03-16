#ifndef GETTER_MACRO_H
#define GETTER_MACRO_H

#define TEAM_STRUCT \
    PLAYER(int, id) \
    PLAYER(const char*, name) \
    PLAYER(int, hp) \

typedef struct {
#define PLAYER(type, something) type something;
    TEAM_STRUCT
#undef PLAYER
} team_t;

#define PLAYER(type, something) \
type get_player_##something(const team_t* team) \
{ \
    return team->something; \
} \

TEAM_STRUCT

#undef PLAYER

#endif
