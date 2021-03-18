#ifndef LOOP_MACRO_H
#define LOOP_MACRO_H

#define M_LOOP(val, min, max) \
    size_t i; \
    for (i = min; i <= max; ++i) { \
        val = i; \
    } \

#endif
