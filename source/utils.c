#include <stdlib.h>

#define MAX_NAME_LENGTH 256

void allocate_empty_string(char **str) {
    *str = (char *) malloc(MAX_NAME_LENGTH);
    (*str)[0] = '\0';

    return;
}
