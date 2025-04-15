#pragma once

#include "context.h"

typedef enum {
    LOAD_DATA,
    CONTEXT_INIT,
    CALCULATE_METRICS
} Operation;

#ifdef __cplusplus
extern "C" {
#endif

void execute(Operation, Context *);

#ifdef __cplusplus
}
#endif
