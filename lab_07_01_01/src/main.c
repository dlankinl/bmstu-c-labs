#include <string.h>

#include "../inc/file_handler.h"
#include "../inc/errors.h"
#include "../inc/key.h"
#include "../inc/mysort.h"

int main(int argc, char **argv)
{
    size_t count = 0;
    FILE *f = NULL;
    int rc = 0;

    if (argc == 3 || argc == 4)
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
            return FILE_ERROR;

        rc = file_count_elems(f, &count);
        if (rc)
            return rc;

        int *arr = calloc(count, sizeof(int));
        int *after_last = arr + count;

        if (arr == after_last)
        {
            free(arr);
            return EMPTY_FILE_ERROR;
        }

        fseek(f, 0, SEEK_SET);
        rc = file_read_array(f, arr, after_last);

        if (rc)
        {
            free(arr);
            return rc;
        }

        fclose(f);

        if (argc == 4 && strcmp(argv[3], "f") == 0)
        {
            int *fil_arr = NULL, *fil_after_last = NULL;

            rc = key(arr, after_last, &fil_arr, &fil_after_last);
            if (rc)
            {
                free(arr);
                return rc;
            }

            mysort(fil_arr, fil_after_last - fil_arr, sizeof(int), comparator);

            f = fopen(argv[2], "w");

            rc = file_write_array(f, fil_arr, fil_after_last);
            if (rc)
            {
                free(arr);
                free(fil_arr);
                return rc;
            }

            fclose(f);
            free(arr);
            free(fil_arr);

            return EXIT_SUCCESS;
        }
        else if (argc == 4)
        {
            printf("Wrong args\n");
            return WRONG_ARGS_ERROR;
        }

        mysort(arr, count, sizeof(int), comparator);

        f = fopen(argv[2], "w");
        if (f == NULL)
        {
            free(arr);
            return FILE_ERROR;
        }

        rc = file_write_array(f, arr, after_last);
        if (rc)
        {
            free(arr);
            return rc;
        }

        fclose(f);
        free(arr);
    }
    else
        return WRONG_ARGS_NUMBER_ERROR;
    return rc;
}