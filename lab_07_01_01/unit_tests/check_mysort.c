#include "../inc/check_mysort.h"

START_TEST(test_norm_arr)
{
    size_t len = 10;

    int src[] = {-543, 6, -5, -6342, 56, 36, 758, 7457, 0, 432};
    int dst[] = {-6342, -543, -5, 0, 6, 36, 56, 432, 758, 7457};

    mysort(src, len, sizeof(int), comparator);

    int rc = arrs_compare(src, dst, len);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_already_sorted)
{
    size_t len = 7;

    int src[] = {-5453, -647, -87, -12, 123, 543, 1000};
    int dst[] = {-5453, -647, -87, -12, 123, 543, 1000};

    mysort(src, len, sizeof(int), comparator);

    int rc = arrs_compare(src, dst, len);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_already_sorted_reverse)
{
    size_t len = 7;

    int src[] = {1000, 543, 123, -12, -87, -647, -5453};
    int dst[] = {-5453, -647, -87, -12, 123, 543, 1000};

    mysort(src, len, sizeof(int), comparator);

    int rc = arrs_compare(src, dst, len);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_one_elem_in_arr)
{
    size_t len = 1;

    int src[] = {432};
    int dst[] = {432};

    mysort(src, len, sizeof(int), comparator);

    int rc = arrs_compare(src, dst, len);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_equal_elems)
{
    size_t len = 10;

    int src[] = {432, 432, 432, 432, 432, 432, 432, 432, 432, 432};
    int dst[] = {432, 432, 432, 432, 432, 432, 432, 432, 432, 432};

    mysort(src, len, sizeof(int), comparator);

    int rc = arrs_compare(src, dst, len);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_ladder)
{
    size_t len = 15;

    int src[] = {-1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1};
    int dst[] = {-1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1};

    mysort(src, len, sizeof(int), comparator);

    int rc = arrs_compare(src, dst, len);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_negatives_only)
{
    size_t len = 12;

    int src[] = {-13, -1, -43, -53, -7, -76, -787, -324, -59, -1234, -5342, -23};
    int dst[] = {-5342, -1234, -787, -324, -76, -59, -53, -43, -23, -13, -7, -1};

    mysort(src, len, sizeof(int), comparator);

    int rc = arrs_compare(src, dst, len);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_positives_only)
{
    size_t len = 12;

    int src[] = {13, 1, 43, 53, 7, 76, 787, 324, 59, 1234, 5342, 23};
    int dst[] = {1, 7, 13, 23, 43, 53, 59, 76, 324, 787, 1234, 5342};

    mysort(src, len, sizeof(int), comparator);

    int rc = arrs_compare(src, dst, len);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* mysort_suite(Suite *suite)
{
    TCase *tc_pos;

    tc_pos = tcase_create("Positives");

    tcase_add_test(tc_pos, test_norm_arr);
    tcase_add_test(tc_pos, test_already_sorted);
    tcase_add_test(tc_pos, test_already_sorted_reverse);
    tcase_add_test(tc_pos, test_one_elem_in_arr);
    tcase_add_test(tc_pos, test_equal_elems);
    tcase_add_test(tc_pos, test_ladder);
    tcase_add_test(tc_pos, test_negatives_only);
    tcase_add_test(tc_pos, test_positives_only);

    suite_add_tcase(suite, tc_pos);

    return suite;
}