#ifndef __MY_STRINGS_H__
#define __MY_STRINGS_H__

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "errors.h"

#define DEC 10
#define HEX 16

int num_len(unsigned long num, int base);

int dec_to_another_base(unsigned long num, int base, char *str, char *symbols, int sign, int remains, int *more_read);

size_t my_strlen(char *str);

void string_reverse(char *str, size_t len);

#endif // __MY_STRINGS_H__