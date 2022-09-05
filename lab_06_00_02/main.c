#include "items.h"
#include "errors.h"

#define ARRAY_LEN 15

int main(int argc, char **argv)
{
    FILE *f = NULL;

    item_t items[ARRAY_LEN];

    if (argc == 3 && argv[1] && !strcmp(argv[2], "ALL"))
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
            return FILE_ERROR;

        size_t arr_size = 0;
        size_t ret_code = arr_fill_from_file(f, items, &arr_size);

        if (!ret_code)
            print_structs(items, arr_size);
        return ret_code;
    }
    else if (argc == 3 && argv[1] && argv[2])
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
            return FILE_ERROR;

        size_t arr_size = 0;
        size_t ret_code = arr_fill_from_file(f, items, &arr_size);

        if (!ret_code)
            ret_code = items_starts_with_substr(items, argv[2], arr_size);

        return ret_code;
    }
    else if (argc == 2 && argv[1])
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
            return FILE_ERROR;

        size_t arr_size = 0;
        size_t ret_code = arr_fill_from_file(f, items, &arr_size);

        double arr_dens[ARRAY_LEN];

        densities(items, arr_size, arr_dens);
        sort_items_by_density(items, arr_size, arr_dens);

        if (!ret_code)
            print_structs(items, arr_size);
        return ret_code;
    }
    else
        return EXIT_FAILURE;

    if (f != NULL)
        fclose(f);
}