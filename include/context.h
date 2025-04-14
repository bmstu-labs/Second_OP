#pragma once

#include "errors.h"

#define MAX_NAME_LENGTH 256

typedef struct {
    char *column_name;
    char *file_name;
    int metric;
    Error error_name;
    char *error_message;
} Context;
