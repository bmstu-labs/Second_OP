#pragma once

#include "errors.h"
#include "data_list.h"

#ifdef __cplusplus
extern "C" {
#endif

ErrorCode allocate_empty_string(char **);

ErrorCode allocate_data_list(DataList **);

#ifdef __cplusplus
}
#endif
