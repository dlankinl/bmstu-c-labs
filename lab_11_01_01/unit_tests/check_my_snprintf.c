#include "check_main.h"

START_TEST(test_my_snprintf_d_1)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    int num = 754;
    res1 = snprintf(s1, MAX_LEN, "I have %d apples.", num);
    res2 = my_snprintf(s2, MAX_LEN, "I have %d apples.", num);

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_d_2)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    int num = -754;
    res1 = snprintf(s1, MAX_LEN, "I have %d apples.", num);
    res2 = my_snprintf(s2, MAX_LEN, "I have %d apples.", num);

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_d_3)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    int num = 9736346;
    res1 = snprintf(s1, MAX_LEN, "I got %d pears.", num);
    res2 = my_snprintf(s2, MAX_LEN, "I got %d pears.", num);

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_d_4)
{
    char s1[16], s2[16];

    int res1, res2;
    int num = INT_MIN;
    res1 = snprintf(s1, 16, "hdsa%d", num);
    res2 = my_snprintf(s2, 16, "hdsa%d", num);

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_c_1)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    res1 = snprintf(s1, MAX_LEN, "You were enrolled to 8%c class.", 'a');
    res2 = my_snprintf(s2, MAX_LEN, "You were enrolled to 8%c class.", 'a');

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_c_2)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    res1 = snprintf(s1, MAX_LEN, "%c%c%c%c%c.", 'C', 'l', 'a', 's', 's');
    res2 = my_snprintf(s2, MAX_LEN, "%c%c%c%c%c.", 'C', 'l', 'a', 's', 's');

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_c_3)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    res1 = snprintf(s1, MAX_LEN, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c.", 'R', 'o', 'o', 'b', 'e', 'z', 'h', 'n', 'e', 'e', 'j', ' ', 'C', 't', 'r', 'l');
    res2 = my_snprintf(s2, MAX_LEN, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c.", 'R', 'o', 'o', 'b', 'e', 'z', 'h', 'n', 'e', 'e', 'j', ' ', 'C', 't', 'r', 'l');

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_x_1)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    int num = 754;
    res1 = snprintf(s1, MAX_LEN, "They`ve encoded it as %x.", num);
    res2 = my_snprintf(s2, MAX_LEN, "They`ve encoded it as %x.", num);

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_x_2)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    int num = 9736346;
    res1 = snprintf(s1, MAX_LEN, "They`ve encoded it as %x.", num);
    res2 = my_snprintf(s2, MAX_LEN, "They`ve encoded it as %x.", num);

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_all_1)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    int num1 = 9736346, num2 = 3214;
    res1 = snprintf(s1, MAX_LEN, "You`ve finally achieved %d points in your %x try (encoded). That`s a %c mark!", num1, num2, 'A');
    res2 = my_snprintf(s2, MAX_LEN, "You`ve finally achieved %d points in your %x try (encoded). That`s a %c mark!", num1, num2, 'A');

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_all_2)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    int num1 = 9736346, num2 = 3214;
    res1 = snprintf(s1, MAX_LEN, "You`ve finally achieved %d points in your %x%d%c try (encoded). That`s a %c %c%c%c%c!", num1, num2, num1 % 150, 'B', 'A', 'm', 'a', 'r', 'k');
    res2 = my_snprintf(s2, MAX_LEN, "You`ve finally achieved %d points in your %x%d%c try (encoded). That`s a %c %c%c%c%c!", num1, num2, num1 % 150, 'B', 'A', 'm', 'a', 'r', 'k');

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_hd_1)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    int num = -754;
    res1 = snprintf(s1, MAX_LEN, "I have %hd apples.", num);
    res2 = my_snprintf(s2, MAX_LEN, "I have %hd apples.", num);

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_hd_2)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    short num = 5325;
    res1 = snprintf(s1, MAX_LEN, "I have %hd apples.", num);
    res2 = my_snprintf(s2, MAX_LEN, "I have %hd apples.", num);

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_ld_1)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    long num = -754235326235;
    res1 = snprintf(s1, MAX_LEN, "I have %ld apples.", num);
    res2 = my_snprintf(s2, MAX_LEN, "I have %ld apples.", num);

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_ld_2)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    long num = 325235453422;
    res1 = snprintf(s1, MAX_LEN, "I have %ld apples.", num);
    res2 = my_snprintf(s2, MAX_LEN, "I have %ld apples.", num);

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_lx_1)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    long num = -754235326235;
    res1 = snprintf(s1, MAX_LEN, "I have %lx apples.", num);
    res2 = my_snprintf(s2, MAX_LEN, "I have %lx apples.", num);

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_lx_2)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    long num = 325235453422;
    res1 = snprintf(s1, MAX_LEN, "I have %lx apples.", num);
    res2 = my_snprintf(s2, MAX_LEN, "I have %lx apples.", num);

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_hx_1)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    short num = -7523;
    res1 = snprintf(s1, MAX_LEN, "I have %hx apples.", num);
    res2 = my_snprintf(s2, MAX_LEN, "I have %hx apples.", num);

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_hx_2)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    short num = 17943;
    res1 = snprintf(s1, MAX_LEN, "I have %hx apples.", num);
    res2 = my_snprintf(s2, MAX_LEN, "I have %hx apples.", num);

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_without_spec)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    int res1, res2;
    res1 = snprintf(s1, MAX_LEN, "Some text here\n");
    res2 = my_snprintf(s2, MAX_LEN, "Some text here\n");

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_zero_x)
{
    char s1[16], s2[16];

    int num = 0;

    int res1, res2;
    res1 = snprintf(s1, 16, "%x", num);
    res2 = my_snprintf(s2, 16, "%x", num);

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_my_snprintf_zero_d)
{
    char s1[16], s2[16];

    int num = 0;

    int res1, res2;
    res1 = snprintf(s1, 16, "%d", num);
    res2 = my_snprintf(s2, 16, "%d", num);

    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(res1, res2);
}
END_TEST

Suite* my_snprintf_suite(Suite *suite)
{
    TCase *tc_pos;

    tc_pos = tcase_create("Positives");

    tcase_add_test(tc_pos, test_my_snprintf_d_1);
    tcase_add_test(tc_pos, test_my_snprintf_d_2);
    tcase_add_test(tc_pos, test_my_snprintf_d_3);
    tcase_add_test(tc_pos, test_my_snprintf_d_4);
    tcase_add_test(tc_pos, test_my_snprintf_c_1);
    tcase_add_test(tc_pos, test_my_snprintf_c_2);
    tcase_add_test(tc_pos, test_my_snprintf_c_3);
    tcase_add_test(tc_pos, test_my_snprintf_x_1);
    tcase_add_test(tc_pos, test_my_snprintf_x_2);
    tcase_add_test(tc_pos, test_my_snprintf_all_1);
    tcase_add_test(tc_pos, test_my_snprintf_all_2);
    tcase_add_test(tc_pos, test_my_snprintf_hd_1);
    tcase_add_test(tc_pos, test_my_snprintf_hd_2);
    tcase_add_test(tc_pos, test_my_snprintf_ld_1);
    tcase_add_test(tc_pos, test_my_snprintf_ld_2);
    tcase_add_test(tc_pos, test_my_snprintf_lx_1);
    tcase_add_test(tc_pos, test_my_snprintf_lx_2);
    tcase_add_test(tc_pos, test_my_snprintf_hx_1);
    tcase_add_test(tc_pos, test_my_snprintf_hx_2);
    tcase_add_test(tc_pos, test_my_snprintf_without_spec);
    tcase_add_test(tc_pos, test_my_snprintf_zero_x);
    tcase_add_test(tc_pos, test_my_snprintf_zero_d);

    suite_add_tcase(suite, tc_pos);

    return suite;
}
