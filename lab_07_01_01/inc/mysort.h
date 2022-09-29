#ifndef __MYSORT_H__
#define __MYSORT_H__

#include <stdlib.h>
#include "arr_handler.h"

void mysort(void *base, size_t num, size_t size, int (*comp)(const void *, const void *));

#endif // __MYSORT_H__