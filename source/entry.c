#include "entry.h"
#include "logic.h"

void execute(Operation operation, Context *context) {
    switch (operation) {
    case LOAD_DATA: {
        context->data = load_csv(
            context->file_path,
            context->region_filter,
            &context->total_rows,
            &context->valid_rows,
            &context->error_rows,
            &context->error
        );
        break;
    }
    case CALCULATE_METRICS: {
        if (!context->data) {
            set_error(&context->error, ERROR_INVALID_DATA);
            break;
        }

        calculate_metrics(
            (DataList *) context->data,
            context->target_column,
            &context->median,
            &context->min,
            &context->max,
            &context->error
        );
        break;
    }
    case CONTEXT_INIT: {
        context_init(context);
        break;
    }
    default:
        set_error(&context->error, ERROR_UNKNOWN_OPERATION);
        break;
    }
}
