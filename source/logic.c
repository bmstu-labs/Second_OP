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

    context->metric = 0;
}
