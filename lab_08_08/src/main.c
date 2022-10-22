#include <stdio.h>
#include <stdlib.h>
#include "../inc/errors.h"
#include "../inc/alloc_free_matrix.h"
#include "../inc/matrix_fill.h"
#include "../inc/print.h"
#include "../inc/matrix_handler.h"

#define MIN(a, b) a < b ? a : b
// #define MAX(a, b) a > b ? a : b

int main(void)
{
    size_t m, n, p, q, k, s;
    size_t rc;
    printf("Введите количество строк и столбцов матрицы A: ");
    if (scanf("%zu %zu", &m, &n) != 2)
        return READ_ERROR;
    printf("Введите количество строк и столбцов матрицы B: ");
    if (scanf("%zu %zu", &p, &q) != 2)
        return READ_ERROR;
    
    int **matr_A = alloc_matrix(m, n);
    if (!matr_A)
        return ALLOC_ERROR;

    int **matr_B = alloc_matrix(p, q);
    if (!matr_B)
        return ALLOC_ERROR;

    rc = fill_matrix(matr_A, m, n);
    if (rc)
        return rc;

    rc = fill_matrix(matr_B, p, q);
    if (rc)
        return rc;

    k = MIN(m, n);
    s = MIN(p, q);    
    
    printf("\n");
    print_matrix(matr_A, m, n);
    printf("\n");
    // print_as_row(matr_A, m, n);
    matrix_reform_to_square(matr_A, m, n, k);
    // printf("\n");
    print_matrix(matr_A, k, k);
    printf("\n");
    // print_as_row(matr_A, k, k);
    // printf("\n");
    // print_matrix(matr_B, p, q);


    printf("%zu - K, %zu - S\n", k, s);

    // free_matrix(matr_A);
    // free_matrix(matr_B);
    free(matr_A);
    free(matr_B);

    return EXIT_SUCCESS;
}
