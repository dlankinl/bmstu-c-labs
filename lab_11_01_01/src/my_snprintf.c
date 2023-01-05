#include "my_snprintf.h"

int my_snprintf(char *s, int n, const char *format, ...)
{
    if (!format || n < 0)
        return EMPTY_FORMAT;

    va_list args;
    va_start(args, format);
    int rc = 0;
    char letter;
    long number;
    int num_sign = 1;
    char *symbols = "0123456789abcdef";

    int printed = 0;
    int read = 0;

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'h':
                    if (*(format + 1) == 'd')
                    {
                        number = (short int) va_arg(args, int);
                        if (number < 0)
                            num_sign = -1;
                        number *= num_sign;
                        printed += dec_to_another_base(number, DEC, s + printed, symbols, num_sign, n - printed - 1, &read);
                    }
                    else if (*(format + 1) == 'x')
                    {
                        number = (unsigned short int) va_arg(args, int);
                        printed += dec_to_another_base(number, HEX, s + printed, symbols, num_sign, n - printed - 1, &read);
                    }
                    format++;
                    break;
                case 'l':
                    if (*(format + 1) == 'd')
                    {
                        number = va_arg(args, long int);
                        if (number < 0)
                            num_sign = -1;
                        number *= num_sign;
                        printed += dec_to_another_base(number, DEC, s + printed, symbols, num_sign, n - printed - 1, &read);
                    }
                    else if (*(format + 1) == 'x')
                    {
                        number = va_arg(args, unsigned long int);
                        printed += dec_to_another_base(number, HEX, s + printed, symbols, num_sign, n - printed - 1, &read);
                    }
                    format++;
                    break;
                case 'c':
                    letter = va_arg(args, int);
                    if (printed < n - 1)
                        s[printed++] = letter;
                    else
                        read++;
                    break;
                case 'd':
                    number = va_arg(args, int);
                    if (number < 0)
                        num_sign = -1;
                    number *= num_sign;
                    printed += dec_to_another_base(number, DEC, s + printed, symbols, num_sign, n - printed - 1, &read);
                    break;
                case 'x':
                    number = va_arg(args, unsigned int);
                    printed += dec_to_another_base(number, HEX, s + printed, symbols, num_sign, n - printed - 1, &read);
                    break;
                default:
                    rc = EXIT_FAILURE;
                    break;
            }
        }
        else
        {
            if (printed < n - 1)
                s[printed++] = *format;
            else
                read++;
        }
        format++;
    }

    va_end(args);

    if (s)
        s[printed] = 0;
    if (rc)
        printed = -1;
        
    return read + printed;
}