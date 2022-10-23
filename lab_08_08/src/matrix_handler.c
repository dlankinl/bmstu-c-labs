#include "../inc/matrix_handler.h"

size_t matrix_reform_to_square(int **matrix, size_t src_rows, size_t src_cols, size_t dst_dims)
{
    size_t rc = EXIT_SUCCESS;
    char *begin = (char *)matrix + src_rows * sizeof(int *);
    if (src_rows == dst_dims)
    {
        size_t iters = src_cols - dst_dims;
        for (size_t i = 0; i < iters; i++)
            del_col(matrix, begin, src_rows, src_cols, src_cols - 1);

        // matrix = realloc(matrix, dst_dims * sizeof(int *) + dst_dims * dst_dims * sizeof(int));
        // if (!matrix)
        //     rc = ALLOC_ERROR;
        // for (size_t i = 0; i < dst_dims; i++)
        //     matrix[i] = (int *)((char *)matrix + dst_dims * sizeof(int *) + i * dst_dims * sizeof(int));
    }
    else if (src_cols == dst_dims)
    {
        size_t iters = src_rows - dst_dims;
        for (size_t i = 0; i < iters; i++)
            del_row(begin, src_rows, src_cols, src_rows - 1);
    }
    else if (src_rows == dst_dims && src_cols == dst_dims)
        rc = EXIT_SUCCESS;
    else
        rc = EXIT_FAILURE;
    return rc;
}

int get_col(int **matrix, int rows, int cols)
{
    int index = 0;
    // int max = **matrix;
    printf("max - %d, %d\n", matrix[0][0], rows);

    for (int i = 0; i < cols; i++)
        index = i;
    return index;
}

void del_col(int **src, char *beg, size_t rows, size_t cols, size_t col_to_delete)
{
    beg++;
    for (size_t i = 0; i < rows; i++)
        for (size_t j = col_to_delete; j < cols - 1; j++)
            src[i][j] = src[i][j + 1];
}

void del_row(char *beg, size_t rows, size_t cols, size_t row_to_delete)
{
    if (row_to_delete != rows - 1)
        memmove(beg + sizeof(int) * cols * row_to_delete, beg + sizeof(int) * cols * (row_to_delete + 1), sizeof(int) * cols * (rows - row_to_delete - 1));
}

int **matrix_copy(int **src, size_t src_rows, size_t src_cols, size_t dst_dims)
{
    int **dst = alloc_matrix(dst_dims, dst_dims);
    if (!dst)
        return NULL;
    for (size_t i = 0; i < src_rows; i++)
        for (size_t j = 0; j < src_cols; j++)
            dst[i][j] = src[i][j];
    return dst;
}

size_t reform_to_z_dims(int **matrix, size_t src_rows, size_t src_cols, size_t dst_dims)
{
    printf("NEVERMING %zu %zu\n\n\n", src_rows, src_cols);
    int **tmp;
    tmp = realloc(matrix, dst_dims * sizeof(int *) + dst_dims * dst_dims * sizeof(int));
    if (!tmp)
        return ALLOC_ERROR;
    free(matrix);
    matrix = alloc_matrix(dst_dims, dst_dims);
    memmove(matrix, tmp, dst_dims * sizeof(int *) + dst_dims * dst_dims * sizeof(int));
    free(tmp);
    for (size_t i = 0; i < dst_dims; i++)
        matrix[i] = (int *)((char *)matrix + dst_dims * sizeof(int *) + i * dst_dims * sizeof(int));

    for (size_t i = 0; i < dst_dims; i++)
    {
        for (size_t j = 0; j < dst_dims; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    // printf("NEVERMIND %zu\n", dst_dims);
    // int **new_matrix = matrix_copy(matrix, src_rows, src_cols, dst_dims);
    
    // for (size_t i = 0; i < dst_dims; i++)
    //     for (size_t j = 0; j )
    
    // if (!new_matrix)
    // {
    //     free(matrix);
    //     return ALLOC_ERROR;
    // }
    // free(matrix);

    // for (size_t i = 0; i < src_cols; i++)
    // {
    //     size_t geom_mean = col_geometric_mean(matrix, src_rows, i);
    //     printf("Geom mean of %zu column is %zu\n", i, geom_mean);
    //     new_matrix[src_rows][i] = geom_mean;
    //     src_rows++;
    // }
    return EXIT_SUCCESS;
}

size_t col_geometric_mean(int **matrix, size_t rows, size_t col)
{
    double mult = 1.0;
    double geom_mean = 0.0;
    for (size_t i = 0; i < rows; i++)
        mult *= fabs((double)matrix[i][col]);
    geom_mean = pow(mult, (double)(1/(double)rows));
    return (size_t)floor(geom_mean);
}