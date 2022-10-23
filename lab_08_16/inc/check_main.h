#ifndef __CHECK_MAIN_H__
#define __CHECK_MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "errors.h"
#include "check_matrix_math.h"
// #include "check_key.h"
// #include "check_file_handler.h"
// #include "check_arr_handler.h"

#define MYEPS 1e-6
#define M 10

// int arrs_compare(int src[], int dst[], size_t len);
int matrix_compare(double **mtr1, double **mtr2, size_t rows, size_t cols);

#endif // __CHECK_MAIN_H__
