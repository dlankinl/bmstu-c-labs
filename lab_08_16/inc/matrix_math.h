#ifndef __MATRIX_MATH_H__
#define __MATRIX_MATH_H__

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "errors.h"

size_t matrix_addition(int **mtr_1, int **mtr_2, int **res, size_t rows, size_t cols);

size_t matrix_multiply(int **mtr_1, int **mtr_2, int **res, size_t rows1, size_t cols1, size_t cols2);

void print_matr(int **matrix, size_t rows, size_t cols);

void swap_rows(int **matrix, size_t index1, size_t index2);

size_t reform_to_triangle(int **matrix, size_t rows, size_t cols);

#endif // __MATRIX_MATH_H__