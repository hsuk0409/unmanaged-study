#include <stdio.h>

#define LENGTH (4096)
#define TRUE (1)
#define FALSE (0)

int main(void)
{

    {
        load_document("hello.txt");
    }

/*
    {
        char* line = NULL;
        char* word = NULL;

        while (TRUE) {
            if (fgets(line, LENGTH, stdin) == NULL) {
                clearerr(stdin);
                break;
            }

            if (sscanf(line, "%s", word) == 1) {
                printf("%s\n", word);
            }
        }
    }
*/    
    return 0;
}
