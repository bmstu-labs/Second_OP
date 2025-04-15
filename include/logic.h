#pragma once

#include "context.h"
#include "data_list.h"

#ifdef __cplusplus
extern "C" {
#endif

DataList *load_csv(const char *, const char *, int *, int *, int *, ErrorInfo *);

void calculate_metrics(DataList *, int, double *, double *, double *, ErrorInfo *);

void context_init(Context *);

void set_error(ErrorInfo *, ErrorCode);

char *get_error_message(const ErrorCode);

#ifdef __cplusplus
}
#endif
