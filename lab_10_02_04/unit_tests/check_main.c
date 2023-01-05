#include "check_main.h"

node_t *to_list_t(int n, ...)
{
    va_list nums;
    node_t *head = NULL;
    va_start(nums, n);
    int power, base;

    for (int i = 0; i < n; i++)
    {
        if (!(i % 2))
            base = va_arg(nums, int);
        else
        {
            power = va_arg(nums, int);
            list_t_push(&head, base, power);
        }
    }
    va_end(nums);
    return head;
}

int list_t_check_equal(node_t *head1, node_t *head2)
{
    node_t *cur1 = head1, *cur2 = head2;
    while (cur1 && cur2)
    {
        if (cur1->base != cur2->base || cur1->power != cur2->power)
            return EXIT_FAILURE;
        // printf("%d - base1, %d - power1, %d - base2, %d - power2\n", cur1->base, cur1->power, cur2->base, cur2->power);

        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return EXIT_SUCCESS;
}

Suite *check_all()
{
    Suite *suite = suite_create("Unit tests");

    suite = list_t_suite(suite);

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
