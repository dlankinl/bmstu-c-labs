#ifndef __MATRIX_MATH_H__
#define __MATRIX_MATH_H__

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "errors.h"

#define EPS 1e-6

size_t matrix_addition(double **mtr_1, double **mtr_2, double **res, size_t rows, size_t cols);

size_t matrix_multiply(double **mtr_1, double **mtr_2, double **res, size_t rows1, size_t cols1, size_t cols2);

void print_matr(double **matrix, size_t rows, size_t cols);

void swap_rows(double **matrix, size_t index1, size_t index2);

void reform_to_triangle(double **matrix, size_t dims);

double determinant(double **matrix, size_t dims);

#endif // __MATRIX_MATH_H__