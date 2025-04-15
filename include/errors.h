#pragma once

typedef enum {
    NO_ERROR,
    ERROR_FILE_NOT_FOUND,
    ERROR_INVALID_COLUMN,
    ERROR_INVALID_DATA,
    ERROR_MEMORY_ALLOCATION,
    ERROR_UNKNOWN_OPERATION
} ErrorCode;

typedef struct {
    ErrorCode code;
    char *message;
} ErrorInfo;
