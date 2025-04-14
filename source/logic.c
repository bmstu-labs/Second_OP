#include "logic.h"
#include "utils.h"
#include "errors.h"

#include <stdlib.h>

void context_init(Context *context) {
    // init column name
    allocate_empty_string(&context->column_name);

    // init filename
    allocate_empty_string(&context->file_name);

    // init error message
    allocate_empty_string(&context->error_message);

    // init error type (name)
    context->error_name = NO_ERRORS;

    // Metric init
    context->metric = 0;
}

void get_error_message(Context *context) {
    switch (context->error_name) {
    case NO_ERRORS:
        context->error_message = "No errors";
        break;
    case MEMORY_ALLOCATION_ERROR:
        context->error_message = "Memory allocation error";
        break;
    default:
        context->error_message = "Unknown error";
        break;
    }
}
