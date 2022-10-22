#ifndef __FILE_HANDLER_H__
#define __FILE_HANDLER_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "errors.h"

#define MAX_LEN 100

size_t file_first_line(FILE *f, size_t *rows, size_t *cols, size_t *non_zero, size_t *input_type);

size_t fill_matr_from_file(FILE *f, int **matrix, size_t rows, size_t cols, size_t non_zero, size_t input_type);

size_t file_mtr_write(FILE *f, int **mtr, size_t rows, size_t cols);

#endif // __FILE_HANDLER_H__