#ifndef __MY_SNPRINTF_H__
#define __MY_SNPRINTF_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "errors.h"
#include "my_strings.h"

int my_snprintf(char *s, int n, const char *format, ...);

#endif // __MY_SNPRINTF_H__