#include "cmd_handler.h"

size_t cmd_out(void)
{
    size_t rc = EXIT_SUCCESS;
    int num;
    if (scanf("%d", &num) != 1 || num < 1)
        return INCORRECT_INPUT;
    
    node_t *head = NULL;
    decompose_number(&head, num);

    list_t_print(head);

    list_t_free(&head);
    return rc;
}

size_t cmd_mul(void)
{
    size_t rc = EXIT_SUCCESS;
    int num1, num2;
    if (scanf("%d %d", &num1, &num2) != 2 || num1 < 1 || num2 < 1)
        return INCORRECT_INPUT;
    
    node_t *head1 = NULL, *head2 = NULL, *head_res = NULL;

    decompose_number(&head1, num1);
    decompose_number(&head2, num2);

    head_res = lists_t_multiplication(head1, head2);

    list_t_print(head_res);
    
    list_t_free(&head1);
    list_t_free(&head2);
    list_t_free(&head_res);
    return rc;
}

size_t cmd_sqr(void)
{
    size_t rc = EXIT_SUCCESS;
    int num;
    if (scanf("%d", &num) != 1 || num < 1)
        return INCORRECT_INPUT;
    
    node_t *head = NULL;
    decompose_number(&head, num);

    list_t_square(head);

    list_t_print(head);

    list_t_free(&head);
    return rc;
}

size_t cmd_div(void)
{
    size_t rc = EXIT_SUCCESS;
    int num1, num2;
    if (scanf("%d %d", &num1, &num2) != 2 || num1 < 1 || num2 < 1)
        return INCORRECT_INPUT;
    if (num1 < num2)
        return ZERO_OUT;
    
    node_t *head1 = NULL, *head2 = NULL, *head_res = NULL;
    decompose_number(&head1, num1);
    decompose_number(&head2, num2);

    head_res = lists_t_division(head1, head2);

    list_t_print(head_res);

    list_t_free(&head1);
    list_t_free(&head2);
    list_t_free(&head_res);
    return rc;
}