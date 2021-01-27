/*
** EPITECH PROJECT, 2019
** sum std arg
** File description:
** sum
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int sum_stdarg(int i, int nb, ...)
{
    va_list ap;
    int sum = 0;

    va_start(ap, nb);
    for (; nb > 0 ; nb--)
        sum += (i == 0) ? va_arg(ap, int) : my_strlen(va_arg(ap, char *));
    va_end(ap);
    return (sum);
}

int disp_stdarg(char *s, ...)
{
    va_list ap;

    va_start(ap, s);
    for (; *s ; s++) {
        switch (*s) {
        case 's':
            my_putstr(va_arg(ap, char *));
            my_putchar('\n');
            break;
        case 'i':
            my_put_nbr(va_arg(ap, int));
            my_putchar('\n');
            break;
        case 'c':
            my_putchar((char) va_arg(ap, int));
            my_putchar('\n');
            break;
        }
    }
    return 0;
}