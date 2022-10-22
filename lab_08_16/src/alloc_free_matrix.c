#include "../inc/alloc_free_matrix.h"

int **alloc_matrix(size_t rows, size_t cols)
{
    // int **data = malloc(rows * sizeof(int *) + rows * cols * sizeof(int));
    int **data = calloc(rows * sizeof(int *) + rows * cols, sizeof(int));
    if (!data)
        return NULL;
    
    for (size_t i = 0; i < rows; i++)
        data[i] = (int *)((char *)data + rows * sizeof(int *) + i * cols * sizeof(int));
    
    return data;
}