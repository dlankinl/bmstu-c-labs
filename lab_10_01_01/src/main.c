#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_t.h"
#include "item_t.h"
#include "errors.h"

int main(int argc, char *argv[])
{
    if (argc < 4 || argc > 5)
        return WRONG_ARGS;
    
    FILE *f = fopen(argv[1], "r");
    if (!f)
        return FILE_ERROR;
    FILE *dst = fopen(argv[2], "w");
    if (!dst)
        return FILE_ERROR;

    node_t *head = NULL;
    item_t *items = malloc(START_ARR_LEN * sizeof(item_t));
    if (!items)
        return ALLOC_ERROR;
    fill_list_from_file(f, &head, items);

    if (!strcmp(argv[3], "sort") && argc == 4)
    {
        head = sort(head, comparator);
        list_t_write_file(dst, head);
    }
    else if (!strcmp(argv[4], "append") && argc == 5)
    {
        FILE *to_append = fopen(argv[3], "r");
        item_t *items2 = malloc(START_ARR_LEN * sizeof(item_t));
        if (!items2)
            return ALLOC_ERROR;
        node_t *head2 = NULL;
        fill_list_from_file(to_append, &head2, items2);
        append(&head, &head2);

        // list_t_print(head);
        list_t_write_file(dst, head);

        free(items2);
        fclose(to_append);
        // list_t_free(&head2);
    }
    // else if (!strcmp(argv[2], "insert"))
    // {
    //     item_t to_insert;
    //     if (scanf(""))
    // }

    free(items);
    list_t_free(&head);
    fclose(f);
    fclose(dst);

    return EXIT_SUCCESS;
}