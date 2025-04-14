#include "utils.h"

#include <stdlib.h>

#define MAX_NAME_LENGTH 256

Error allocate_empty_string(char **str) {
    Error result = NO_ERRORS;
    *str = (char *) malloc(MAX_NAME_LENGTH);
    if (*str == NULL) {
        result = MEMORY_ALLOCATION_ERROR;
    }
    else {
        (*str)[0] = '\0';
    }

    return result;
}

