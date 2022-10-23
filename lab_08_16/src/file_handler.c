#include "../inc/file_handler.h"

size_t file_first_line(FILE *f, size_t *rows, size_t *cols, size_t *non_zero)
{
    char str[MAX_LEN];
    fgets(str, MAX_LEN, f);
    str[strlen(str) - 1] = 0;

    char *istr;
    istr = strtok(str, " ");

    size_t counter = 0;
    while (istr != NULL)
    {
        if (!atoi(istr))
            return INCORRECT_INPUT;
        if (!counter)
            *rows = atoi(istr);
        else if (counter == 1)
            *cols = atoi(istr);
        else if (counter == 2)
            *non_zero = atoi(istr);
        istr = strtok(NULL, " ");
        counter++;
    }
    return EXIT_SUCCESS;
}

size_t fill_matr_from_file(FILE *f, double **matrix, size_t non_zero)
{
    size_t row, col;
    double num;
    for (size_t i = 0; i < non_zero; i++)
    {
        if (fscanf(f, "%zu %zu %lf", &row, &col, &num) != 3)
            return INCORRECT_INPUT;
        matrix[row - 1][col - 1] = num;
    }
    return EXIT_SUCCESS;
}

size_t file_mtr_write(FILE *f, double **mtr, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
            if (fprintf(f, "%.6lf ", mtr[i][j]) < 0)
                return WRITE_ERROR;
        fprintf(f, "\n");
    }
    return EXIT_SUCCESS;
}