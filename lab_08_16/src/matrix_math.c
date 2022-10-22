#include "../inc/matrix_math.h"

size_t matrix_addition(int **mtr_1, int **mtr_2, int **res, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            res[i][j] = mtr_1[i][j] + mtr_2[i][j];
    return EXIT_SUCCESS;
}

size_t matrix_multiply(int **mtr_1, int **mtr_2, int **res, size_t rows1, size_t cols1, size_t cols2)
{
    for(size_t i = 0; i < rows1; i++)
        for(size_t j = 0; j < cols2; j++)
        {
            for(size_t k = 0; k < cols1; k++)
                res[i][j] += mtr_1[i][k] * mtr_2[k][j];
        }
    return EXIT_SUCCESS;
}

void print_matr(int **matrix, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void swap_rows(int **matrix, size_t index1, size_t index2)
{
    int *tmp = matrix[index1];
    matrix[index1] = matrix[index2];
    matrix[index2] = tmp;
}

size_t reform_to_triangle(int **matrix, size_t rows, size_t cols)
{
    double num;
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
        {
            num = (double)matrix[i][j];
            matrix[i][j] = num;
        }

    int max;
    size_t index;
    for (size_t i = 0; i < cols; i++)
    {
        index = 0;
        max = abs(matrix[0][i]);
        for (size_t j = 1; j < rows; j++)
        {
            if (abs(matrix[j][i]) > max)
            {
                index = j;
                max = abs(matrix[j][i]);
            }
        }
        swap_rows(matrix, 0, index);

        for (size_t j = 1; j < rows; j++)
            for (size_t k = 0; k < cols; k++)
                matrix[j][k] -= matrix[0][k] * (double)(matrix[j][k] / matrix[0][i]);
        
    }
    return EXIT_SUCCESS;
}