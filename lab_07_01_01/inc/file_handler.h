#ifndef __FILE_HANDLER_H__
#define __FILE_HANDLER_H__

#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

int file_write_array(FILE *f, const int *begin, const int *end);

int file_read_array(FILE *f, const int *arr, const int *pend);

int file_count_elems(FILE *f, size_t *count);

#endif // __FILE_HANDLER_H__