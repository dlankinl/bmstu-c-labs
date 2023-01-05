#ifndef __CHECK_MAIN_H__
#define __CHECK_MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <check.h>
#include <stdarg.h>
#include "errors.h"
#include "check_list_t.h"
#include "list_t.h"

// node_t *to_list_t(int n, ...);
node_t *items_to_list_t(item_t *items, int n, ...);

// int list_t_check_equal(node_t *head1, node_t *head2);
int list_t_check_equal_items(node_t *head1, node_t *head2, int (*comparator)(const void *, const void *));

#endif // __CHECK_MAIN_H__
