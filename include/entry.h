#pragma once

#include "context.h"

typedef enum {
    CALCULATE_MEDIAN,
    CALCULATE_MINIMUM,
    CALCULATE_MAXIMUM,
    OPEN_FILE
} Operation;

void execute(Operation, Context *);
