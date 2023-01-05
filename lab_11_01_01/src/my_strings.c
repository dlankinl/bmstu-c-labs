#include "my_strings.h"

int num_len(unsigned long num, int base)
{
    size_t len = 0;
    if (!num)
        return 1;
    while (num != 0)
    {
        num /= base;
        len++;
    }
    return len;
}

int num_reverse(int num)
{
    int remainder, reverse = 0;
    while (num)
    {
        remainder = num % 10;
        reverse = reverse * 10 + remainder;
        num /= 10;
    }
    return reverse;
}

void string_reverse(char *str, size_t len)
{
    char tmp;
    for (size_t i = 0; i < len / 2; i++)
    {
        tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

int dec_to_another_base(unsigned long num, int base, char *str, char *symbols, int sign, int remains, int *more_read)
{
    int len = num_len(num, base);
    int i = 0, digit = 0;
    char *tmp = malloc((len + 2) * sizeof(char));
    if (!num)
    {
        if (remains)
        {
            *str = '0';
            str++;
        }
        free(tmp);
        return 1;
    }
    while (num)
    {
        digit = num % base;
        tmp[i++] = symbols[digit];
        num /= base;
    }
    if (sign == -1)
        tmp[i++] = '-';
    tmp[i] = 0;
    string_reverse(tmp, i);
    int to_print = 0;
    if (i >= remains)
        to_print = remains;
    else
        to_print = i;

    for (int j = 0; j < to_print; j++)
    {
        *str = tmp[j];
        str++;
    }

    *more_read += i - to_print;
    free(tmp);
    return to_print;
}

size_t my_strlen(char *str)
{
    size_t len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}
