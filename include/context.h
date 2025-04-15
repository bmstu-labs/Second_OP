#pragma once

#include "errors.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    // Data
    void *data;

    // Operation params
    char *file_path;
    char *region_filter;
    int target_column;

    // Operation results
    double median;
    double min;
    double max;

    // Load stats
    int total_rows;
    int valid_rows;
    int error_rows;

    // Errors
    ErrorInfo error;
} Context;

#ifdef __cplusplus
}
#endif
