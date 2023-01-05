#include "list_t.h"

item_t *resize_arr(item_t *items, size_t amount)
{
    item_t *ptmp = realloc(items, amount * sizeof(item_t));
    if (!ptmp)
        return NULL;
    return ptmp;
}

void list_t_free(node_t **head)
{
    node_t *cur = NULL;
    while ((*head)->next)
    {
        cur = (*head);
        (*head) = (*head)->next;
        free(cur);
    }
    free(*head);
}

int fill_list_from_file(FILE *f, node_t **head, item_t *items)
{
    size_t max = START_ARR_LEN;
    size_t counter = 0;

    size_t weight, price;
    while (fscanf(f, "%zu %zu", &weight, &price) == 2)
    {
        if (counter >= max)
        {
            max *= 2;
            resize_arr(items, max);
        }
        items[counter].weight = weight;
        items[counter].price = price;
        (*head) = list_push(*head, (void *)(&items[counter]));
        counter++;
    }

    return EXIT_SUCCESS;
}

int comparator(const void *l, const void *r)
{
    return *((int *) l) - *((int *) r);
}

void list_t_print(node_t *head)
{
    item_t *item;
    while (head)
    {
        item = head->data;
        printf("%zu %zu\n", item->weight, item->price);
        head = head->next;
    }
}

node_t *list_push(node_t *head, void *data)
{
    node_t *to_push = init_node(data);
    node_t *cur = head;
    if (!cur)
        return to_push;
    while (cur->next)
        cur = cur->next;
    cur->next = to_push;
    return head;
}

node_t *init_node(void *data)
{
    node_t *node = malloc(sizeof(node_t));
    if (node)
    {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *))
{
    node_t *cur = head;
    while (cur)
    {
        if (!comparator(cur->data, data))
            return cur;
    
        cur = cur->next;
    }

    return NULL;
}

void insert(node_t **head, node_t *elem, node_t *before)
{
    if (!head || !elem || !before)
        return;
    
    if (*head == before)
    {
        elem->next = before;
        *head = elem;
    }
    else
    {
        node_t *cur = *head;
        while (cur->next)
        {
            if (cur->next == before)
            {
                cur->next = elem;
                elem->next = before;
            }
            cur = cur->next;
        }
    }
}

void *pop_front(node_t **head)
{
    node_t *tmp;
    void *data = NULL;
    if (head && *head)
    {
        tmp = *head;
        data = tmp->data;
        *head = (*head)->next;
        free(tmp);
    }
    return data;
}

void append(node_t **node_a, node_t **node_b)
{
    while (*node_b)
    {
        void *data = pop_front(node_b);
        *node_a = list_push(*node_a, data);
    }
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    node_t *new = NULL, *cur = head, *next = NULL;
    
    while (cur)
    {
        next = cur->next;
        sorted_insert(&new, cur, comparator);
        cur = next;
    }
    return new;
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void*, const void*))
{
    if (!(*head))
    {
        element->next = NULL;
        *head = element;
        return;
    }
    node_t *cur = *head, *prev = NULL;
    while (cur && comparator(cur->data, element->data) < 0)
    {
        prev = cur;
        cur = cur->next;
    }

    if (prev)
        prev->next = element;
    else
        *head = element;

    element->next = cur;
}

void list_t_write_file(FILE *f, node_t *head)
{
    item_t cur;
    while (head)
    {
        item_t *tmp = (item_t *) head->data;
        cur.weight = tmp->weight;
        cur.price = tmp->price;
        fprintf(f, "%zu %zu\n", cur.weight, cur.price);
        head = head->next;
    }
}