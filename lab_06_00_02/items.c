#include "items.h"
#include "errors.h"

int str_scanf(FILE *f, char str[], size_t n)
{
    char str_in[ITEM_NAME_LEN + 2];
    if (fgets(str_in, n + 1, f) == NULL)
        return EXIT_FAILURE;
    printf("%s\n", str_in);
    size_t len = strlen(str_in);
    if (len == 0)
        return EXIT_FAILURE;
    if (str_in[len - 1] == '\n')
        str_in[len - 1] = '\0';
    if (strlen(str_in) > n - 1)
        return EXIT_FAILURE;
    strncpy(str, str_in, n);
    return EXIT_SUCCESS;
}

size_t arr_fill_from_file(FILE *f, item_t items[], size_t *arr_size)
{
    if (fseek(f, 0L, SEEK_END))
        return EMPTY_FILE_ERROR;

    size_t size = ftell(f);
    fseek(f, 0L, SEEK_SET);
    if (!size)
        return EMPTY_FILE_ERROR;

    *arr_size = 0;

    char line[ITEM_NAME_LEN + 1];
    while (!feof(f))
    {
        fgets(line, ITEM_NAME_LEN + 1, f);
        line[strlen(line) - 1] = 0;
        strcpy(items[*arr_size].name, line);
        fscanf(f, "%lf", &items[*arr_size].weight);
        fscanf(f, "%lf", &items[*arr_size].volume);
        getc(f); // лишний символ
        ++(*arr_size);
    }
    --(*arr_size);

    return EXIT_SUCCESS;
}

void print_struct(item_t item)
{
    printf("%s\n%.6lf\n%.6lf\n", item.name, item.weight, item.volume);
}

void print_structs(item_t items[], size_t amount)
{
    for (size_t i = 0; i < amount; i++)
        printf("%s\n%.6lf\n%.6lf\n", items[i].name, items[i].weight, items[i].volume);
}

size_t items_starts_with_substr(item_t items[], char substr[], size_t amount)
{
    size_t count = 0;
    for (size_t i = 0; i < amount; i++)
    {
        if (strstr(items[i].name, substr) - items[i].name == 0)
        {
            count++;
            print_struct(items[i]);
        }
    }
    if (!count)
        return NO_MATCHES_ERROR;
    return EXIT_SUCCESS;
}

size_t densities(item_t items[], size_t amount, double densities[])
{
    for (size_t i = 0; i < amount; i++)
    {
        if (fabs(items[i].volume) > MY_EPS)
            densities[i] = items[i].weight / items[i].volume;
        else
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

size_t sort_items_by_density(item_t items[], size_t amount, double densities[])
{
    for (size_t i = 0; i < amount; i++)
    {
        size_t min_pos = i;
        for (size_t j = i + 1; j < amount; j++)
            if (densities[min_pos] > densities[j])
                min_pos = j;
        double tmp = densities[min_pos];
        densities[min_pos] = densities[i];
        densities[i] = tmp;

        item_t tmp_item = items[min_pos];
        items[min_pos] = items[i];
        items[i] = tmp_item;
    }

    return EXIT_SUCCESS;
}