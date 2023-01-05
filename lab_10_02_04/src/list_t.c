#include "list_t.h"

size_t list_t_push(node_t **head, int base, int power)
{
    node_t *tmp = malloc(sizeof(node_t));
    size_t rc = EXIT_SUCCESS;
    if (tmp)
    {
        tmp->base = base;
        tmp->power = power;
        tmp->next = *head;
        *head = tmp;
    }
    else 
        rc = ALLOC_ERROR;
    return rc;
}

size_t list_t_pop(node_t **head)
{
    size_t rc = EXIT_SUCCESS;
    if (!head)
        rc = EMPTY_LIST;
    else
    {
        node_t *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    return rc;
}

void decompose_number(node_t **head, int num)
{
    int div = 2;
    size_t count;
    while (num > 1)
    {
        count = 0;
        while (!(num % div))
        {
            count++;
            num /= div;
        }
        if (count)
            list_t_push(head, div, count);
        div++;
    }
}

void list_t_print(const node_t *head)
{
    while (head)
    {
        printf("%d %d ", head->base, head->power);
        head = head->next;
    }
    printf("1\n");
}

int comparator(const void *l, const void *r)
{
    return *((int *) l) - *((int *) r);
}

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *))
{
    node_t *cur = head;
    while (cur)
    {
        if (!comparator(&cur->base, data))
            return cur;

        cur = cur->next;
    }

    return NULL;
}

node_t *lists_t_multiplication(node_t *head1, node_t *head2)
{
    int max_div = head1->base > head2->base ? head1->base : head2->base;
    int div = 2, base, power;
    node_t *head_res = NULL;
    node_t *tmp1, *tmp2;
    while (div < max_div + 1)
    {
        tmp1 = find(head1, &div, comparator);
        tmp2 = find(head2, &div, comparator);
        if (tmp1 || tmp2)
        {
            base = div;
            power = 0;
            if (tmp1 && tmp1->base == div)
                power += tmp1->power;
            if (tmp2 && tmp2->base == div)
                power += tmp2->power;

            list_t_push(&head_res, base, power);
        }
        div++;
    }
    return head_res;
}

node_t *lists_t_division(node_t *head1, node_t *head2)
{
    int max_mult = head1->base > head2->base ? head1->base : head2->base;
    int mult = 2, base, power;
    node_t *head_res = NULL;
    node_t *tmp1, *tmp2;
    while (mult < max_mult + 1)
    {
        tmp1 = find(head1, &mult, comparator);
        tmp2 = find(head2, &mult, comparator);
        if (tmp1 && tmp2)
        {
            base = mult;
            power = tmp1->power - tmp2->power;

            if (power)
                list_t_push(&head_res, base, power);
        }
        else if (tmp1)
        {
            base = mult;
            power = tmp1->power;
            list_t_push(&head_res, base, power);
        }
        else if (tmp2)
        {
            base = mult;
            power = tmp2->power;
            list_t_push(&head_res, base, power);
        }
        mult++;
    }
    return head_res;
}

void list_t_square(node_t *head)
{
    node_t *tmp = head;
    while (tmp)
    {
        tmp->power *= 2;
        tmp = tmp->next;
    }
}

void list_t_free(node_t **head)
{
    node_t *cur, *next;
    if (*head)
    {
        cur = *head;
        while (cur)
        {
            next = cur->next;
            free(cur);
            cur = next;
        }
        *head = NULL;
    }
}