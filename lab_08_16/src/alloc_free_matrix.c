#include "../inc/alloc_free_matrix.h"

double **alloc_matrix(size_t rows, size_t cols)
{
    // int **data = malloc(rows * sizeof(int *) + rows * cols * sizeof(int));
    double **data = calloc(rows * sizeof(double *) + rows * cols, sizeof(double));
    if (!data)
        return NULL;
    
    for (size_t i = 0; i < rows; i++)
        data[i] = (double *)((char *)data + rows * sizeof(double *) + i * cols * sizeof(double));
    
    return data;
}