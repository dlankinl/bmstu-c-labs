#include "../inc/file_handler.h"

int file_write_array(FILE *f, const int *begin, const int *end)
{
    if (f == NULL)
        return FILE_ERROR;

    int *beg = (int *)begin;

    while (beg < end)
    {
        fprintf(f, "%d\n", *beg);
        beg++;
    }
    return EXIT_SUCCESS;
}

int file_read_array(FILE *f, const int *arr, const int *pend)
{
    int *cur = (int *)arr;
    while (cur < pend)
    {
        if (fscanf(f, "%d", cur) != 1)
            return READ_ERROR;
        cur++;
    }

    return EXIT_SUCCESS;
}

int file_count_elems(FILE *f, size_t *count)
{
    int num;
    while (!feof(f))
    {
        if (fscanf(f, "%d", &num) == 1)
            ++(*count);
        else
            return READ_ERROR;
    }

    return EXIT_SUCCESS;
}