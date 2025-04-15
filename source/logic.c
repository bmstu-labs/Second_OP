#include "logic.h"
#include "utils.h"
#include "errors.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024

void context_init(Context *context) {
    context->data = 0;

    // init column name
    allocate_empty_string(&context->file_path);

    // init filename
    allocate_empty_string(&context->region_filter);

    // init error info
    set_error(&context->error, NO_ERROR);
}

char *get_error_message(const ErrorCode error) {
    char *error_message = NULL;
    switch (error) {
    case NO_ERROR:
        error_message = "No errors";
        break;
    case ERROR_MEMORY_ALLOCATION:
        error_message = "Memory allocation error";
        break;
    case ERROR_UNKNOWN_OPERATION:
        error_message = "Unknown operation";
        break;
    default:
        error_message = "Unknown error";
        break;
    }

    return error_message;
}

void set_error(ErrorInfo *buffer, ErrorCode error) {
    buffer->code = error;
    buffer->message = get_error_message(buffer->code);
}

DataList *load_csv(const char *path,
                   const char *region_filter,
                   int *total_rows,
                   int *valid_rows,
                   int *error_rows,
                   ErrorInfo *error) {
    FILE *file = fopen(path, "r");
    if (!file) {
        set_error(error, ERROR_FILE_NOT_FOUND);
    }

    DataList *data;
    ErrorCode result = allocate_data_list(&data);

    char line[MAX_LINE_LENGTH];
    *total_rows = 0;
    *valid_rows = 0;
    *error_rows = 0;

    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        (*total_rows)++;

        char* token = strtok(line, ",");
        if (!token) {
            (*error_rows)++;
            continue;
        }

        char* region = strdup(token);
        if (region_filter && strcmp(region, region_filter) != 0) {
            free(region);
            continue;
        }

        double* columns = NULL;
        int column_count = 0;
        int parse_error = 0;

        while ((token = strtok(NULL, ",\n"))) {
            char* end;
            double value = strtod(token, &end);

            if (end == token || *end != '\0') { // Ошибка парсинга
                parse_error = 1;
                break;
            }

            double* temp = realloc(columns, (column_count + 1) * sizeof(double));
            if (!temp) {
                parse_error = 1;
                break;
            }

            columns = temp;
            columns[column_count++] = value;
        }

        if (parse_error || column_count == 0) {
            (*error_rows)++;
            free(region);
            free(columns);
            continue;
        }

        DataEntry* entry = data_entry_create(region, columns, column_count);
        if (!entry) {
            error->code = 2;
            error->message = strdup("Memory allocation failed");
            fclose(file);
            data_list_free(list);
            return NULL;
        }

        entry->next = list->head;
        list->head = entry;
        list->count++;
        (*valid_rows)++;

        free(region);
        free(columns);
    }

    fclose(file);
    return list;
}
