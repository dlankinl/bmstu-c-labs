#include "../inc/errors.h"
#include "../inc/alloc_free_matrix.h"
#include "../inc/file_handler.h"
#include "../inc/matrix_math.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char **argv)
{
    if (argc == 5)
    {
        FILE *file_1, *file_2;
        size_t rc = EXIT_SUCCESS;
        file_1 = fopen(argv[2], "r");
        file_2 = fopen(argv[3], "r");

        if (!file_1 || !file_2)
            return FILE_ERROR;

        size_t rows1 = 0, rows2 = 0;
        size_t cols1 = 0, cols2 = 0;
        size_t non_zero1 = 0, non_zero2 = 0;
        // size_t input_type1 = 0, input_type2 = 0;
                
        file_first_line(file_1, &rows1, &cols1, &non_zero1);
        double **mtr_1 = alloc_matrix(rows1, cols1);
        if (!mtr_1)
            return ALLOC_ERROR;

        file_first_line(file_2, &rows2, &cols2, &non_zero2);
        double **mtr_2 = alloc_matrix(rows2, cols2);
        if (!mtr_2)
            return ALLOC_ERROR;

        rc = fill_matr_from_file(file_1, mtr_1, non_zero1);
        if (rc)
            return rc;

        rc = fill_matr_from_file(file_2, mtr_2, non_zero2);
        if (rc)
            return rc;


        // printf("\n");
        // print_matr(mtr_1, rows1, cols1);
        // printf("\n");
        // print_matr(mtr_2, rows2, cols2);
        // printf("\n");

        double **res;


        if (strcmp(argv[1], "a") == 0)
        {
            if (rows1 != rows2 || cols1 != cols2)
                return NOT_EQUAL_DIMENSIONS_ERROR;
            res = alloc_matrix(rows1, cols1);
            matrix_addition(mtr_1, mtr_2, res, rows1, cols2);
            // print_matr(res, rows1, cols1);
            // printf("\n");
            FILE *file_res = fopen(argv[4], "w");
            if (!file_res)
                return FILE_ERROR;
            file_mtr_write(file_res, res, rows1, cols1);
            fclose(file_res);
        }
        else if (strcmp(argv[1], "m") == 0)
        {
            if (cols1 != rows2)
                return NOT_SUITABLE_DIMENSIONS_ERROR;
            res = alloc_matrix(rows1, cols2);
            matrix_multiply(mtr_1, mtr_2, res, rows1, cols1, cols2);
            // print_matr(res, rows1, cols1);
            // printf("\n");
            FILE *file_res = fopen(argv[4], "w");
            if (!file_res)
                return FILE_ERROR;
            file_mtr_write(file_res, res, rows2, cols1);
            fclose(file_res);
        }
        else
            return WRONG_ARGS;

        free(mtr_1);
        free(mtr_2);
        fclose(file_1);
        fclose(file_2);
    }
    else if (argc == 4 && strcmp(argv[1], "o") == 0)
    {
        FILE *file, *res;
        size_t rc = EXIT_SUCCESS;
        file = fopen(argv[2], "r");
        res = fopen(argv[3], "w");

        if (!file || !res)
            return FILE_ERROR;

        size_t rows = 0, cols = 0, non_zero = 0;
                
        file_first_line(file, &rows, &cols, &non_zero);
        double **mtr = alloc_matrix(rows, cols);
        if (!mtr)
            return ALLOC_ERROR;

        rc = fill_matr_from_file(file, mtr, non_zero);
        if (rc)
        {
            free(mtr);
            return rc;
        }

        // printf("\n");
        // print_matr(mtr, rows, cols);
        // printf("\n");

        if (cols != rows)
            return NOT_EQUAL_DIMENSIONS_ERROR;
        // reform_to_triangle(mtr, rows);
        double det = determinant(mtr, rows);
        fprintf(res, "%.6lf", det);
        free(mtr);
        fclose(file);
        fclose(res);
        // printf("DET = %lf\n", det);
        // print_matr(mtr, rows, cols);
        // printf("\n");
    }
    else
        return WRONG_ARGS;
    return EXIT_SUCCESS;
}