#include "../inc/errors.h"
#include "../inc/alloc_matrix.h"
#include "../inc/file_handler.h"
#include "../inc/matrix_math.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char **argv)
{
    if (argc == 5 && (strcmp(argv[1], "a") == 0 || strcmp(argv[1], "m") == 0))
    {
        FILE *file_1, *file_2;
        size_t rc1 = EXIT_SUCCESS, rc2 = EXIT_SUCCESS;

        file_1 = fopen(argv[2], "r");
        file_2 = fopen(argv[3], "r");
        if (!file_1 || !file_2)
            return FILE_ERROR;

        size_t rows1 = 0, rows2 = 0;
        size_t cols1 = 0, cols2 = 0;
        size_t non_zero1 = 0, non_zero2 = 0;
                
        rc1 = file_first_line(file_1, &rows1, &cols1, &non_zero1);
        rc2 = file_first_line(file_2, &rows2, &cols2, &non_zero2);
        if (rc1 || rc2)
        {
            fclose(file_1);
            fclose(file_2);
            return rc1;
        }
        // if (rc)
        // {
        //     free(mtr_1);
        //     fclose(file_1);
        //     fclose(file_2);
        //     return rc;
        // }
        double **mtr_1 = alloc_matrix(rows1, cols1);
        double **mtr_2 = alloc_matrix(rows2, cols2);
        if (!mtr_1 || !mtr_2)
        {
            fclose(file_1);
            fclose(file_2);
            return ALLOC_ERROR;
        }

        rc = fill_matr_from_file(file_1, mtr_1, non_zero1);
        if (rc)
        {
            free(mtr_1);
            free(mtr_2);
            fclose(file_1);
            fclose(file_2);
            return rc;
        }

        rc = fill_matr_from_file(file_2, mtr_2, non_zero2);
        if (rc)
        {
            free(mtr_1);
            free(mtr_2);
            fclose(file_1);
            fclose(file_2);
            return rc;
        }

        double **res;

        if (strcmp(argv[1], "a") == 0)
        {
            if (rows1 != rows2 || cols1 != cols2)
            {
                free(mtr_1);
                free(mtr_2);
                fclose(file_1);
                fclose(file_2);
                return NOT_EQUAL_DIMENSIONS_ERROR;
            }
            res = alloc_matrix(rows1, cols1);
            if (!res)
            {
                free(mtr_1);
                free(mtr_2);
                fclose(file_1);
                fclose(file_2);
                return ALLOC_ERROR;
            }
            matrix_addition(mtr_1, mtr_2, res, rows1, cols2);
            FILE *file_res = fopen(argv[4], "w");
            if (!file_res)
            {
                free(mtr_1);
                free(mtr_2);
                free(res);
                fclose(file_1);
                fclose(file_2);
                return FILE_ERROR;
            }
            file_mtr_write(file_res, res, rows1, cols1);
            free(res);
            fclose(file_res);
        }
        else if (strcmp(argv[1], "m") == 0)
        {
            if (cols1 != rows2)
            {
                free(mtr_1);
                free(mtr_2);
                fclose(file_1);
                fclose(file_2);
                return NOT_SUITABLE_DIMENSIONS_ERROR;
            }
            res = alloc_matrix(rows1, cols2);
            if (!res)
            {
                free(mtr_1);
                free(mtr_2);
                fclose(file_1);
                fclose(file_2);
                return ALLOC_ERROR;
            }
            matrix_multiply(mtr_1, mtr_2, res, rows1, cols1, cols2);
            FILE *file_res = fopen(argv[4], "w");
            if (!file_res)
            {
                free(mtr_1);
                free(mtr_2);
                free(res);
                fclose(file_1);
                fclose(file_2);
                return FILE_ERROR;
            }
            file_mtr_write(file_res, res, rows2, cols1);
            free(res);
            fclose(file_res);
        }

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
                
        rc = file_first_line(file, &rows, &cols, &non_zero);
        if (rc)
        {
            fclose(file);
            fclose(res);
            return rc;
        }
        double **mtr = alloc_matrix(rows, cols);
        if (!mtr)
        {
            fclose(file);
            fclose(res);
            return ALLOC_ERROR;
        }

        rc = fill_matr_from_file(file, mtr, non_zero);
        if (rc)
        {
            free(mtr);
            fclose(file);
            fclose(res);
            return rc;
        }

        if (cols != rows)
        {
            free(mtr);
            fclose(file);
            fclose(res);
            return NOT_EQUAL_DIMENSIONS_ERROR;
        }
        double det = determinant(mtr, rows);
        fprintf(res, "%d", (int)round(det));
        free(mtr);
        fclose(file);
        fclose(res);
    }
    else
        return WRONG_ARGS;
    return EXIT_SUCCESS;
}