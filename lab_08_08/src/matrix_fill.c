#include "../inc/matrix_fill.h"

size_t fill_matrix(int **matrix, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            if (scanf("%d", &matrix[i][j]) != 1)
                return INCORRECT_INPUT;
    return EXIT_SUCCESS;
}
