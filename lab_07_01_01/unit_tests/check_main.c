#include "../inc/check_main.h"

int arrs_compare(int src[], int dst[], size_t len)
{
    for (size_t i = 0; i < len; i++)
        if (src[i] != dst[i])
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

Suite *check_all()
{
    Suite *suite = suite_create("Unit tests");

    suite = mysort_suite(suite);
    suite = key_suite(suite);

    return suite;
}

int main(void)
{
    size_t success = 0;
    Suite *suite = check_all();
    SRunner *runner;

    runner = srunner_create(suite);

    srunner_run_all(runner, CK_VERBOSE);
    success = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (success == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
