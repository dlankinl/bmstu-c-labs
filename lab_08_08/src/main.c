#include <stdio.h>
#include <stdlib.h>
#include "../inc/errors.h"
#include "../inc/alloc_free_matrix.h"
#include "../inc/matrix_fill.h"
#include "../inc/print.h"
#include "../inc/matrix_handler.h"

#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

int main(void)
{
    size_t m, n, p, q, k, s;
    size_t rc;
    if (scanf("%zu %zu", &m, &n) != 2)
        return READ_ERROR;
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
    
    printf("\nA before:\n");
    print_matrix(matr_A, m, n);
    printf("\nA after:\n");
    matrix_reform_to_square(matr_A, m, n, k);
    print_matrix(matr_A, k, k);
    printf("\n\nB before:\n");
    print_matrix(matr_B, p, q);
    printf("\nB after:\n");
    matrix_reform_to_square(matr_A, p, q, s);
    print_matrix(matr_B, s, s);
    printf("\n");
    // print_as_row(matr_A, k, k);
    // printf("\n");
    // print_matrix(matr_B, p, q);

    size_t z;
    z = MAX(k, s);


    printf("%zu - K, %zu - S, %zu - Z\n", k, s, z);

    reform_to_z_dims(matr_A, k, k, z);
    // reform_to_z_dims(matr_B, s, s, z);

    // printf("\nA after adding row:\n");
    // print_matrix(matr_A, k + 1, k);
    // printf("\nB after adding row:\n");
    // print_matrix(matr_B, k + 1, k);

    // free_matrix(matr_A);
    // free_matrix(matr_B);

    free(matr_A);
    free(matr_B);

    return EXIT_SUCCESS;
}
