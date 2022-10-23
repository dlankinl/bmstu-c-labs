#include "../inc/matrix_math.h"

size_t matrix_addition(double **mtr_1, double **mtr_2, double **res, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            res[i][j] = mtr_1[i][j] + mtr_2[i][j];
    return EXIT_SUCCESS;
}

size_t matrix_multiply(double **mtr_1, double **mtr_2, double **res, size_t rows1, size_t cols1, size_t cols2)
{
    for(size_t i = 0; i < rows1; i++)
        for(size_t j = 0; j < cols2; j++)
        {
            for(size_t k = 0; k < cols1; k++)
                res[i][j] += mtr_1[i][k] * mtr_2[k][j];
        }
    return EXIT_SUCCESS;
}

void print_matr(double **matrix, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
            printf("%d ", (int)matrix[i][j]);
        printf("\n");
    }
}

void swap_rows(double **matrix, size_t index1, size_t index2)
{
    double *tmp = matrix[index1];
    matrix[index1] = matrix[index2];
    matrix[index2] = tmp;
}

void reform_to_triangle(double **matrix, size_t dims)
{
    size_t index;
    for (size_t i = 0; i < dims; i++)
    {
        index = i;  
        for (size_t j = i; j < dims; j++)
            if (fabs(matrix[j][i]) > fabs(matrix[index][i]))
                index = j;
        swap_rows(matrix, i, index);

        for (size_t j = i + 1; j < dims; j++)
        {
            double multiplier = matrix[j][i] / matrix[i][i];
            for (size_t k = 0; k < dims; k++)
                matrix[j][k] -= matrix[i][k] * multiplier;
        }
    }

    // for (size_t i = 0; i < dims; i++)
    // {
    //     for (size_t j = 0; j < dims; j++)
    //         printf("%lf ", matrix[i][j]);
    //     printf("\n");
    // }
}

double determinant(double **matrix, size_t dims)
{
    double dtrmnt = 1.0;
    reform_to_triangle(matrix, dims);
    for (size_t i = 0; i < dims; i++)
        dtrmnt *= matrix[i][i];
    return dtrmnt;
}