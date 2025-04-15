#pragma once

typedef struct DataEntry {
    char *region;
    double *columns;
    int column_count;
    struct DataEntry *next;
} DataEntry;

typedef struct {
    DataEntry *head;
    int count;
} DataList;

#ifdef __cplusplus
extern "C" {
#endif

DataEntry *data_entry_init()

#ifdef __cplusplus
}
#endif
