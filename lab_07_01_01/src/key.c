#include "../inc/key.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (pb_src == NULL || pe_src == NULL || pb_src >= pe_src)
        return INCORRECT_ARRAY_ERROR;

    int *min = NULL, *max = NULL;

    size_t rc = min_max_adr(pb_src, pe_src, &min, &max);
    if (rc)
        return rc;

    int *beg, *end;
    int count = (int)(max - min);
    if (count > 0)
    {
        beg = min + 1;
        end = max;
        count--;
    }
    else
    {
        beg = max + 1;
        end = min;
        count++;
        count = abs(count);
    }

    if (count == 0)
        return NO_SUITABLES_ERROR;

    *pb_dst = (int *) calloc(count, sizeof(int));

    fill_filtered_arr(pb_dst, pe_dst, beg, end);

    return EXIT_SUCCESS;
}