/*
** EPITECH PROJECT, 2019
** printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

char *output1(const char *format, va_list ap, int *flags);

char *flag(const char *format, va_list ap, int *flags)
{
    switch (format[0]) {
    case '#':
        flags[0] = 1;
        return (flag(format + 1, ap, flags));
    case '0':
        flags[1] = 1;
        return (flag(format + 1, ap, flags));
    case '-':
        flags[2] = 1;
        return (flag(format + 1, ap, flags));
    case ' ':
        flags[3] = 1;
        return (flag(format + 1, ap, flags));
    case '+':
        flags[4] = 1;
        return (flag(format + 1, ap, flags));
    default:
        return (output1(format, ap, flags));
    }
}

int is_output(char c)
{
    char outputs[12] = "disScoxXpu%";

    for (int i = 0 ; outputs[i] ; i++) {
        if (c == outputs[i])
            return 1;
    }
    return 0;
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int len = 0;
    char *to_print;
    int flags[5] = {0};

    va_start(ap, format);
    for (int i = 0 ; format[i] ; i++) {
        if (format[i] == '%') {
            to_print = flag(format + 1 + i, ap, flags);
            len += my_strlen(to_print);
            my_putstr(to_print);
            i++;
            for (; is_output(format[i]) == 0 ; i++);
        }
        else {
            my_putchar(format[i]);
            len++;
        }
    }
    return len;
}