#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUM_LINES (5)
#define LINE_LENGTH (2048)

int main(void)
{
    char* lines[NUM_LINES];
    char line[LINE_LENGTH];
    size_t i;
    size_t j;

    for (i = 0 ; i < NUM_LINES; ++i) {
        if (!fgets(line, LINE_LENGTH, stdin)) {
            clearerr(stdin);
            break;
        }
        
        lines[i] = malloc(strlen(line) + 1);
        strcpy(lines[i], line);
    }

    for (j = 0; j < i; ++j) {
        printf("%s", lines[j]);
    }

    for (j = 0; j < i; ++j) {
        free(lines[j]);
        lines[j] = NULL;
    }
    
    return 0;
}
