#ifndef __LIST_T_H__
#define __LIST_T_H__

#include <stdlib.h>
#include <stdio.h>
#include "errors.h"
#include "constants.h"

typedef struct node_t node_t;

struct node_t
{
    int base;
    int power;
    node_t *next;
};

size_t list_t_push(node_t **head, int base, int power);

size_t list_t_pop(node_t **head);

void decompose_number(node_t **head, int num);

void list_t_print(const node_t *head);

int comparator(const void *l, const void *r);

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *));

node_t *lists_t_multiplication(node_t *head1, node_t *head2);

node_t *lists_t_division(node_t *head1, node_t *head2);

void list_t_square(node_t *head);

void list_t_free(node_t **head);

#endif // __LIST_T_H__