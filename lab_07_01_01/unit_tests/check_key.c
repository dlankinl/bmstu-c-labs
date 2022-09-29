#include "../inc/check_key.h"

START_TEST(test_norm_arr)
{
    size_t len_src = 16;

    int pb_src[] = {2441, 2172, 1012, 3695, -2736, 3464, 4174, 3141, -3000, 1022, 2455, 8165, 3872, 1607, 9991, 3736};
    int *pe_src = pb_src + len_src;

    int *pb_dst = NULL, *pe_dst = NULL;

    size_t len_correct = 5;
    int correct[] = {1022, 2455, 8165, 3872, 1607};

    key(pb_src, pe_src, &pb_dst, &pe_dst);

    int rc = arrs_compare(pb_dst, correct, len_correct);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_negatives_only)
{
    size_t len_src = 11;

    int pb_src[] = {-849, -879, -804, -799, -50, -73, -234, -622, -542, -903, -987};
    int *pe_src = pb_src + len_src;

    int *pb_dst = NULL, *pe_dst = NULL;

    size_t len_correct = 5;
    int correct[] = {-73, -234, -622, -542, -903};

    key(pb_src, pe_src, &pb_dst, &pe_dst);

    int rc = arrs_compare(pb_dst, correct, len_correct);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_positives_only)
{
    size_t len_src = 13;

    int pb_src[] = {4430, 6459, 5679, 1253, 5699, 6703, 3671, 8219, 2577, 4402, 3284, 2918, 2515};
    int *pe_src = pb_src + len_src;

    int *pb_dst = NULL, *pe_dst = NULL;

    size_t len_correct = 3;
    int correct[] = {5699, 6703, 3671};

    key(pb_src, pe_src, &pb_dst, &pe_dst);

    int rc = arrs_compare(pb_dst, correct, len_correct);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_equal_elems)
{
    size_t len_src = 7;

    int pb_src[] = {1, 1, 1, 1, 1, 1, 1};
    int *pe_src = pb_src + len_src;

    int *pb_dst = NULL, *pe_dst = NULL;

    int rc = key(pb_src, pe_src, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, NO_SUITABLES_ERROR);
}

Suite* key_suite(Suite *suite)
{
    TCase *tc_pos, *tc_neg;

    tc_pos = tcase_create("Positives");

    tcase_add_test(tc_pos, test_norm_arr);
    tcase_add_test(tc_pos, test_negatives_only);
    tcase_add_test(tc_pos, test_positives_only);

    suite_add_tcase(suite, tc_pos);

    tc_neg = tcase_create("Negatives");

    tcase_add_test(tc_neg, test_equal_elems);

    suite_add_tcase(suite, tc_neg);

    return suite;
}