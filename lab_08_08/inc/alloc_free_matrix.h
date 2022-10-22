#ifndef __ALLOC_FREE_MATRIX_H__
#define __ALLOC_FREE_MATRIX_H__

#include <stdlib.h>
#include <stdio.h>
#include "errors.h"

int **alloc_matrix(size_t rows, size_t cols);

void free_matrix(int **ptrs);


#endif // __ALLOC_FREE_MATRIX_H__