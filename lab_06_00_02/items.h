#ifndef __ITEMS_H__
#define __ITEMS_H__

#include <inttypes.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ITEM_NAME_LEN 25
#define NAME_LEN 10
#define NUM_OF_SUBJECTS 4
#define ARRAY_LEN 15
#define MY_EPS 1e-6

typedef struct
{
    char name[ITEM_NAME_LEN + 1];
    double weight;
    double volume;
} item_t;

int str_scanf(FILE *f, char str[], size_t n);

size_t arr_fill_from_file(FILE *f, item_t items[], size_t *arr_size);

void print_struct(item_t item);

void print_structs(item_t items[], size_t amount);

size_t items_starts_with_substr(item_t items[], char substr[], size_t amount);

size_t densities(item_t items[], size_t amount, double densities[]);

size_t sort_items_by_density(item_t items[], size_t amount, double densities[]);

#endif // __ITEMS_H__