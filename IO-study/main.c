#include <stdio.h>

#include "file_io.h"

#define LENGTH (4096)
#define TRUE (1)
#define FALSE (0)

int main(void)
{
    /* 파일에서 문자 하나씩 읽어서 동적 할당하여 저장하기 */
    {
        load_document("hello.txt");
    }
/*
    {
        char line[LENGTH];
        char word[LENGTH];

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
