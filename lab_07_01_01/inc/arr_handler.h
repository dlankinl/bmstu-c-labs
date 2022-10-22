#ifndef __ARR_HANDLER_H__
#define __ARR_HANDLER_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "errors.h"

int comparator(const void *l, const void *r);

void swap(char *change_on, char *to_change, size_t size);

size_t min_max_adr(const int *begin, const int *end, int **min_adr, int **max_adr);

void fill_filtered_arr(int **pb_dst, int **pe_dst, int *beg, int *end);

#endif // __ARR_HANDLER_H__