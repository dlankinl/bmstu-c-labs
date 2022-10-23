#ifndef __MATRIX_HANDLER_H__
#define __MATRIX_HANDLER_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "errors.h"
#include "alloc_free_matrix.h"

size_t matrix_reform_to_square(int **matrix, size_t src_rows, size_t src_cols, size_t dst_dims);

int get_col(int **src, int rows, int cols);

void del_col(int **src, char *beg, size_t rows, size_t cols, size_t col_ind);

void del_row(char *beg, size_t rows, size_t cols, size_t row_to_delete);

size_t reform_to_z_dims(int **matrix, size_t src_rows, size_t src_cols, size_t dst_dims);

size_t col_geometric_mean(int **matrix, size_t rows, size_t col);

#endif // __MATRIX_HANDLER_H__