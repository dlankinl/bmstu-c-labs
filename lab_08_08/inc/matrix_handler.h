#ifndef __MATRIX_HANDLER_H__
#define __MATRIX_HANDLER_H__

#include <stdlib.h>
#include <stdio.h>
#include "errors.h"

size_t matrix_reform_to_square(int **matrix, size_t src_rows, size_t src_cols, size_t dst_dims);

int get_col(int **src, int rows, int cols);

void del_col(int **src, char *beg, size_t rows, size_t cols, size_t col_ind);

#endif // __MATRIX_HANDLER_H__