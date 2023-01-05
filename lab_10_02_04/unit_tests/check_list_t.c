#include "check_list_t.h"

START_TEST(test_out_1)
{
    node_t *head = NULL, *ideal = NULL;
    int num = 366;
    decompose_number(&head, num);

    ideal = to_list_t(6, 2, 1, 3, 1, 61, 1);

    int rc = list_t_check_equal(head, ideal);

    list_t_free(&ideal);
    list_t_free(&head);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_out_2)
{
    node_t *head = NULL, *ideal = NULL;
    int num = 657458375;
    decompose_number(&head, num);

    ideal = to_list_t(8, 5, 3, 7, 1, 53, 1, 14177, 1);

    int rc = list_t_check_equal(head, ideal);

    list_t_free(&ideal);
    list_t_free(&head);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_out_3)
{
    node_t *head = NULL, *ideal = NULL;
    int num = 15752961;
    decompose_number(&head, num);

    ideal = to_list_t(4, 3, 8, 7, 4);

    int rc = list_t_check_equal(head, ideal);

    list_t_free(&ideal);
    list_t_free(&head);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_mul_1)
{
    node_t *head1 = NULL, *head2 = NULL, *res = NULL, *ideal = NULL;
    int num1 = 243, num2 = 534;
    decompose_number(&head1, num1);
    decompose_number(&head2, num2);

    ideal = to_list_t(6, 2, 1, 3, 6, 89, 1);
    res = lists_t_multiplication(head1, head2);

    int rc = list_t_check_equal(res, ideal);

    list_t_free(&head1);
    list_t_free(&head2);
    list_t_free(&res);
    list_t_free(&ideal);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_mul_2)
{
    node_t *head1 = NULL, *head2 = NULL, *res = NULL, *ideal = NULL;
    int num1 = 8, num2 = 14;
    decompose_number(&head1, num1);
    decompose_number(&head2, num2);

    ideal = to_list_t(4, 2, 4, 7, 1);
    res = lists_t_multiplication(head1, head2);

    int rc = list_t_check_equal(res, ideal);

    list_t_free(&head1);
    list_t_free(&head2);
    list_t_free(&res);
    list_t_free(&ideal);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_mul_3)
{
    node_t *head1 = NULL, *head2 = NULL, *res = NULL, *ideal = NULL;
    int num1 = 800, num2 = 123;
    decompose_number(&head1, num1);
    decompose_number(&head2, num2);

    ideal = to_list_t(8, 2, 5, 3, 1, 5, 2, 41, 1);
    res = lists_t_multiplication(head1, head2);

    int rc = list_t_check_equal(res, ideal);

    list_t_free(&head1);
    list_t_free(&head2);
    list_t_free(&res);
    list_t_free(&ideal);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_sqr_1)
{
    node_t *head = NULL, *ideal = NULL;
    int num = 1432;
    decompose_number(&head, num);
    list_t_square(head);

    ideal = to_list_t(4, 2, 6, 179, 2);

    int rc = list_t_check_equal(head, ideal);

    list_t_free(&head);
    list_t_free(&ideal);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_sqr_2)
{
    node_t *head = NULL, *ideal = NULL;
    int num = 14641;
    decompose_number(&head, num);
    list_t_square(head);

    ideal = to_list_t(2, 11, 8);

    int rc = list_t_check_equal(head, ideal);

    list_t_free(&head);
    list_t_free(&ideal);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_sqr_3)
{
    node_t *head = NULL, *ideal = NULL;
    int num = 235;
    decompose_number(&head, num);
    list_t_square(head);

    ideal = to_list_t(4, 5, 2, 47, 2);

    int rc = list_t_check_equal(head, ideal);

    list_t_free(&head);
    list_t_free(&ideal);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_div_1)
{
    node_t *head1 = NULL, *head2 = NULL, *res = NULL, *ideal = NULL;
    int num1 = 235, num2 = 47;
    decompose_number(&head1, num1);
    decompose_number(&head2, num2);

    ideal = to_list_t(2, 5, 1);
    res = lists_t_division(head1, head2);

    int rc = list_t_check_equal(res, ideal);

    list_t_free(&head1);
    list_t_free(&head2);
    list_t_free(&res);
    list_t_free(&ideal);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_div_2)
{
    node_t *head1 = NULL, *head2 = NULL, *res = NULL, *ideal = NULL;
    int num1 = 94732, num2 = 4;
    decompose_number(&head1, num1);
    decompose_number(&head2, num2);

    ideal = to_list_t(4, 11, 1, 2153, 1);
    res = lists_t_division(head1, head2);

    int rc = list_t_check_equal(res, ideal);

    list_t_free(&head1);
    list_t_free(&head2);
    list_t_free(&res);
    list_t_free(&ideal);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_div_3)
{
    node_t *head1 = NULL, *head2 = NULL, *res = NULL, *ideal = NULL;
    int num1 = 715862707, num2 = 3043;
    decompose_number(&head1, num1);
    decompose_number(&head2, num2);

    ideal = to_list_t(4, 7, 2, 4801, 1);
    res = lists_t_division(head1, head2);

    int rc = list_t_check_equal(res, ideal);

    list_t_free(&head1);
    list_t_free(&head2);
    list_t_free(&res);
    list_t_free(&ideal);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* list_t_suite(Suite *suite)
{
    TCase *tc_pos;

    tc_pos = tcase_create("Positives");

    tcase_add_test(tc_pos, test_out_1);
    tcase_add_test(tc_pos, test_out_2);
    tcase_add_test(tc_pos, test_out_3);
    tcase_add_test(tc_pos, test_mul_1);
    tcase_add_test(tc_pos, test_mul_2);
    tcase_add_test(tc_pos, test_mul_3);
    tcase_add_test(tc_pos, test_sqr_1);
    tcase_add_test(tc_pos, test_sqr_2);
    tcase_add_test(tc_pos, test_sqr_3);
    tcase_add_test(tc_pos, test_div_1);
    tcase_add_test(tc_pos, test_div_2);
    tcase_add_test(tc_pos, test_div_3);

    suite_add_tcase(suite, tc_pos);

    return suite;
}
