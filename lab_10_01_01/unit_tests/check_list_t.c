#include "check_list_t.h"

START_TEST(test_list_find_1)
{
    node_t *head = NULL, *res = NULL;

    FILE *f = fopen("./func_tests/data/pos_02_in.txt", "r");

    item_t *items = malloc(START_ARR_LEN * sizeof(item_t));
    fill_list_from_file(f, &head, items);

    item_t to_find = {5, 6};
    res = find(head, (const void*)(&to_find), comparator);

    item_t found;
    found = *((item_t *)res->data);

    int rc = (found.weight == to_find.weight && found.price == to_find.price) ? EXIT_SUCCESS : EXIT_FAILURE;

    fclose(f);
    
    list_t_free(&head);
    free(items);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_list_find_2)
{
    node_t *head = NULL, *res = NULL;
    
    FILE *f = fopen("./func_tests/data/pos_01_in.txt", "r");
    item_t *items = malloc(START_ARR_LEN * sizeof(item_t));
    fill_list_from_file(f, &head, items);

    item_t to_find = {6500, 80};
    res = find(head, (const void*)(&to_find), comparator);

    item_t found;
    found = *((item_t *)res->data);

    int rc = (found.weight == to_find.weight && found.price == to_find.price) ? EXIT_SUCCESS : EXIT_FAILURE;

    fclose(f);

    list_t_free(&head);
    free(items);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_list_append_1)
{
    node_t *head1 = NULL, *head2 = NULL, *ideal_res = NULL;
    item_t *items1 = malloc(START_ARR_LEN * sizeof(item_t));
    item_t *items2 = malloc(START_ARR_LEN * sizeof(item_t));
    FILE *f1 = fopen("./func_tests/data/pos_01_in.txt", "r");
    fill_list_from_file(f1, &head1, items1);
    fclose(f1);
    FILE *f2 = fopen("./func_tests/data/pos_02_in.txt", "r");
    fill_list_from_file(f2, &head2, items2);
    fclose(f2);

    append(&head1, &head2);

    item_t *items_res = malloc(9 * sizeof(item_t));
    FILE *res = fopen("./func_tests/data/pos_02_out.txt", "r");
    fill_list_from_file(res, &ideal_res, items_res);
    fclose(res);

    int rc = list_t_check_equal_items(head1, ideal_res, comparator);

    free(items1);
    free(items2);
    free(items_res);
    list_t_free(&head1);
    list_t_free(&ideal_res);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_list_append_2)
{
    node_t *head1 = NULL, *head2 = NULL, *ideal_res = NULL;
    item_t *items1 = malloc(START_ARR_LEN * sizeof(item_t));
    item_t *items2 = malloc(START_ARR_LEN * sizeof(item_t));
    FILE *f1 = fopen("./func_tests/data/pos_02_in.txt", "r");
    fill_list_from_file(f1, &head1, items1);
    fclose(f1);
    FILE *f2 = fopen("./func_tests/data/pos_01_in.txt", "r");
    fill_list_from_file(f2, &head2, items2);
    fclose(f2);

    append(&head1, &head2);

    item_t *items_res = malloc(9 * sizeof(item_t));
    FILE *res = fopen("./func_tests/data/pos_01_out.txt", "r");
    fill_list_from_file(res, &ideal_res, items_res);
    fclose(res);

    int rc = list_t_check_equal_items(head1, ideal_res, comparator);

    free(items1);
    free(items2);
    free(items_res);
    list_t_free(&head1);
    list_t_free(&ideal_res);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_list_insert_1)
{
    node_t *head = NULL, *ideal_res = NULL, *found = NULL, *to_ins = NULL;
    item_t *items = malloc(START_ARR_LEN * sizeof(item_t));
    item_t *items_res = malloc(6 * sizeof(item_t));
    FILE *f = fopen("./func_tests/data/pos_02_in.txt", "r");
    fill_list_from_file(f, &head, items);
    fclose(f);

    item_t to_find = {5, 6};
    found = find(head, (const void*)(&to_find), comparator);

    item_t to_insert = {0, 0};
    to_ins = init_node((void *)&to_insert);

    insert(&head, to_ins, found);

    ideal_res = items_to_list_t(items_res, 12, 1, 2, 3, 4, 0, 0, 5, 6, 7, 8, 9, 10);

    int rc = list_t_check_equal_items(head, ideal_res, comparator);

    free(items);
    free(items_res);
    list_t_free(&head);
    list_t_free(&ideal_res);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_list_insert_2)
{
    node_t *head = NULL, *ideal_res = NULL, *found = NULL, *to_ins = NULL;
    item_t *items = malloc(START_ARR_LEN * sizeof(item_t));
    item_t *items_res = malloc(6 * sizeof(item_t));
    FILE *f = fopen("./func_tests/data/pos_02_in.txt", "r");
    fill_list_from_file(f, &head, items);
    fclose(f);

    item_t to_find = {1, 2};
    found = find(head, (const void*)(&to_find), comparator);

    item_t to_insert = {0, 0};
    to_ins = init_node((void *)&to_insert);

    insert(&head, to_ins, found);

    ideal_res = items_to_list_t(items_res, 12, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

    int rc = list_t_check_equal_items(head, ideal_res, comparator);

    free(items);
    free(items_res);
    list_t_free(&head);
    list_t_free(&ideal_res);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_list_sorted_insert_1)
{
    node_t *head = NULL, *ideal_res = NULL;
    item_t *items = malloc(START_ARR_LEN * sizeof(item_t));
    item_t *items_res = malloc(5 * sizeof(item_t));
    FILE *f = fopen("./func_tests/data/pos_03_in.txt", "r");
    fill_list_from_file(f, &head, items);
    fclose(f);

    item_t to_insert = {5, 6};
    node_t *to_ins = init_node((void *)&to_insert);

    sorted_insert(&head, to_ins, comparator);

    ideal_res = items_to_list_t(items_res, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    int rc = list_t_check_equal_items(head, ideal_res, comparator);

    free(items);
    free(items_res);
    list_t_free(&head);
    list_t_free(&ideal_res);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_list_sorted_insert_2)
{
    node_t *head = NULL, *ideal_res = NULL;
    item_t *items = malloc(START_ARR_LEN * sizeof(item_t));
    item_t *items_res = malloc(3 * sizeof(item_t));
    FILE *f = fopen("./func_tests/data/pos_04_in.txt", "r");
    fill_list_from_file(f, &head, items);
    fclose(f);

    item_t to_insert = {7, 8};
    node_t *to_ins = init_node((void *)&to_insert);

    sorted_insert(&head, to_ins, comparator);

    ideal_res = items_to_list_t(items_res, 4, 1, 2, 7, 8);
    int rc = list_t_check_equal_items(head, ideal_res, comparator);

    free(items);
    free(items_res);
    list_t_free(&head);
    list_t_free(&ideal_res);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_list_sort_1)
{
    node_t *head = NULL, *ideal_res = NULL;
    item_t *items = malloc(START_ARR_LEN * sizeof(item_t));
    item_t *res_items = malloc(START_ARR_LEN * sizeof(item_t));
    FILE *f = fopen("./func_tests/data/pos_05_in.txt", "r");
    fill_list_from_file(f, &head, items);
    fclose(f);

    ideal_res = items_to_list_t(res_items, 8, 1, 9, 2, 6, 4, 5, 7, 3);

    head = sort(head, comparator);

    int rc = list_t_check_equal_items(head, ideal_res, comparator);

    free(items);
    free(res_items);
    list_t_free(&head);
    list_t_free(&ideal_res);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_list_sort_2)
{
    node_t *head = NULL, *ideal_res = NULL;
    item_t *items = malloc(START_ARR_LEN * sizeof(item_t));
    item_t *res_items = malloc(START_ARR_LEN * sizeof(item_t));
    FILE *f = fopen("./func_tests/data/pos_06_in.txt", "r");
    fill_list_from_file(f, &head, items);
    fclose(f);

    ideal_res = items_to_list_t(res_items, 20, 1, 9, 2, 8, 3, 7, 4, 6, 5, 5, 6, 4, 7, 3, 8, 2, 9, 1);

    head = sort(head, comparator);

    int rc = list_t_check_equal_items(head, ideal_res, comparator);

    free(items);
    free(res_items);
    list_t_free(&head);
    list_t_free(&ideal_res);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* list_t_suite(Suite *suite)
{
    TCase *tc_pos;

    tc_pos = tcase_create("Positives");

    tcase_add_test(tc_pos, test_list_find_1);
    tcase_add_test(tc_pos, test_list_find_2);
    tcase_add_test(tc_pos, test_list_append_1);
    tcase_add_test(tc_pos, test_list_append_2);
    tcase_add_test(tc_pos, test_list_insert_1);
    tcase_add_test(tc_pos, test_list_insert_2);
    tcase_add_test(tc_pos, test_list_sorted_insert_1);
    tcase_add_test(tc_pos, test_list_sorted_insert_2);
    tcase_add_test(tc_pos, test_list_sort_1);
    tcase_add_test(tc_pos, test_list_sort_2);

    suite_add_tcase(suite, tc_pos);

    return suite;
}
