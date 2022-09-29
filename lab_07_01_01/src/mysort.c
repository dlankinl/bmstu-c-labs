#include "../inc/mysort.h"

void mysort(void *base, size_t num, size_t size, int (*comp)(const void *, const void *))
{
    char *pend = (char *)base + num * size;
    char *i = (char *)base;
    char *j;

    for (; i < pend - size; i += size)
        for (j = i + size; j < pend; j += size)
            if (comp(i, j) > 0)
                swap(i, j, size);
}