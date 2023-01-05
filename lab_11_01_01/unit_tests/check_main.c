#include "check_main.h"

int compare_strings(char *s1, int len1, char *s2, int len2)
{
    if (len1 != len2)
        return EXIT_FAILURE;
    
    for (int i = 0; i < len1; i++)
    {
        if (*s1++ != *s2++)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

Suite *check_all()
{
    Suite *suite = suite_create("Unit tests");

    suite = my_snprintf_suite(suite);

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
