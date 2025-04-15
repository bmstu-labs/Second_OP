#include "utils.h"
#include "data_list.h"

#include <stdlib.h>

#define MAX_NAME_LENGTH 256

ErrorCode allocate_empty_string(char **str) {
    ErrorCode result = NO_ERROR;
    *str = (char *) malloc(MAX_NAME_LENGTH);
    if (!*str) {
        result = ERROR_MEMORY_ALLOCATION;
    }
    else {
        (*str)[0] = '\0';
    }

    return result;
}

ErrorCode allocate_data_list(DataList **list) {
    ErrorCode result = NO_ERROR;
    *list = (DataList *) malloc(sizeof(DataList));
    if (!*list) {
        result = ERROR_MEMORY_ALLOCATION;
    }
    else {
        (*list)->head = 0;
        (*list)->count = 0;
    }

    return result;
}

