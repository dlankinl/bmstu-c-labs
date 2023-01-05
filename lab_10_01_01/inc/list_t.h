#ifndef __LIST_T_H__
#define __LIST_T_H__

#include <stdlib.h>
#include <stdio.h>
#include "errors.h"
#include "item_t.h"

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

int fill_list_from_file(FILE *f, node_t **head, item_t *items);

void list_t_print(node_t *head);

node_t *list_push(node_t *head, void *data);

void list_t_free(node_t **head);

int comparator(const void *l, const void *r);

node_t *init_node(void *data);

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *));

void insert(node_t **head, node_t *elem, node_t *before);

void append(node_t **head_a, node_t **head_b);

node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

void list_t_write_file(FILE *f, node_t *head);

#endif // __LIST_T_H__