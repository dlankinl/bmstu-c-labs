#include "../inc/matrix_handler.h"

size_t matrix_reform_to_square(int **matrix, size_t src_rows, size_t src_cols, size_t dst_dims)
{
    size_t rc = EXIT_SUCCESS;
    if (src_rows == dst_dims)
    {
        size_t iters = src_cols - dst_dims;
        char *begin = (char *)matrix + src_rows * sizeof(int *);
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
        matrix = realloc(matrix, dst_dims * sizeof(int *) + dst_dims * dst_dims * sizeof(int));
        if (!matrix)
            rc = ALLOC_ERROR;
        for (size_t i = 0; i < dst_dims; i++)
            matrix[i] = (int *)((char *)matrix + dst_dims * sizeof(int *) + i * dst_dims * sizeof(int));
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

void del_col(int **src, char *beg, size_t rows, size_t cols, size_t col_ind)
{
    beg++;
    for (size_t i = 0; i < rows; i++)
        for (size_t j = col_ind; j < cols - 1; j++)
            src[i][j] = src[i][j + 1];
}

// void del_row(int rows, int cols, char *beg, int row_ind)
// {
//     // output(src, rows - 1, cols);
//     // printf("\n");

//     // for (int i = row_ind; i < rows - 1; i++)
//     // {
//     //     src[i] = src[i + 1];
//     // }
//     // printf("after swap pointers\n");
//     // output(src, rows - 1, cols);
//     // printf("\n");

//     if (row_ind != rows - 1)
//     {
//         memmove(beg + sizeof(matrix_t) * cols * row_ind,
//             beg + sizeof(matrix_t) * cols * (row_ind + 1),
//             sizeof(matrix_t) * cols * (rows - row_ind - 1));
//     }
//     // output(src, rows - 1, cols);
//     // printf("\n");
// }