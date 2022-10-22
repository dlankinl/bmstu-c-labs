#include "../inc/arr_handler.h"

int comparator(const void *l, const void *r)
{
    return *((int *) l) - *((int *) r);
}

void swap(char *change_on, char *to_change, size_t size)
{
    while (size != 0)
    {
        char tmp = *change_on;
        *(change_on++) = *to_change;
        *(to_change++) = tmp;
        size--;
    }
}

size_t min_max_adr(const int *begin, const int *end, int **min_adr, int **max_adr)
{
    *min_adr = (int *)begin;
    *max_adr = (int *)begin;
    int *cur = (int *)begin;
    int min = *begin, max = *begin;
    while (cur < end)
    {
        if (*cur > max)
        {
            max = *cur;
            *max_adr = cur;
        }
        else if (*cur < min)
        {
            min = *cur;
            *min_adr = cur;
        }
        cur++;
    }
    if (min == max)
        return NO_SUITABLES_ERROR;
    return EXIT_SUCCESS;
}

void fill_filtered_arr(int **pb_dst, int **pe_dst, int *beg, int *end)
{
    int *cur = beg;
    int *pb_fil_arr = *pb_dst;

    while (cur < end)
    {
        *pb_fil_arr = *cur;
        pb_fil_arr++;
        cur++;
    }
    *pe_dst = pb_fil_arr;
}