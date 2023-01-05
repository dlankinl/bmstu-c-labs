#include "check_main.h"

node_t *items_to_list_t(item_t *items, int n, ...)
{
    va_list nums;
    node_t *head = NULL;
    va_start(nums, n);
    size_t weight, price;

    for (int i = 0; i < n / 2; i++)
    {
        weight = va_arg(nums, int);
        price = va_arg(nums, int);
        items[i].weight = weight;
        items[i].price = price;
        head = list_push(head, (void *)(&items[i]));
    }
    va_end(nums);

    return head;
}

int list_t_check_equal_items(node_t *head1, node_t *head2, int (*comparator)(const void *, const void *))
{
    node_t *cur1 = head1, *cur2 = head2;
    while (cur1 && cur2)
    {
        if (comparator(cur1->data, cur2->data))
            return EXIT_FAILURE;

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

    // srunner_set_fork_status(runner, CK_NOFORK);

    srunner_run_all(runner, CK_VERBOSE);
    success = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (success == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
