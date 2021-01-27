/*
** EPITECH PROJECT, 2019
** output flags
** File description:
** output
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *convert(char *base, unsigned long num);

char *my_nb_to_str(long long nb, int *flags)
{
    char *dest = malloc(25);
    int i = 0;
    long long num = (nb < 0) ? -nb : nb;

    for (; num ; i++) {
        dest[i] = num % 10 + 48;
        num /= 10;
    }
    if (nb < 0)
        dest[i++] = '-';
    else if (flags[4] || flags[3])
        dest[i++] = (flags[4]) ? '+' : ' ';
    dest[i] = 0;
    my_revstr(dest);
    return (dest);
}

char *my_ull_to_str(unsigned long long nb)
{
    char *dest = malloc(25);
    int i = 0;

    for (; nb ; i++) {
        dest[i] = nb % 10 + 48;
        nb /= 10;
    }
    dest[i] = 0;
    my_revstr(dest);
    return (dest);
}

char *output3(const char *format, va_list ap, int *flags)
{
    switch (format[0]) {
    case 'd':
        return (my_nb_to_str(va_arg(ap, int), flags));
    case 'i':
        return (my_nb_to_str(va_arg(ap, int), flags));
    default:
        return (0);
    }
}

char *output2(const char *format, va_list ap, int *flags)
{
    char *dest = malloc(2);

    switch (format[0]) {
    case 'c':
        dest[0] = (char) va_arg(ap, int);
        dest[1] = 0;
        return dest;
    case 's':
        return (va_arg(ap, char *));
    case 'S':
        return (my_nprint(va_arg(ap, char *)));
    case 'p':
        dest = "0x";
        return (my_strcat(dest, 
        convert("01234656789abcdef", (unsigned long long) va_arg(ap, void *))));
    case '%':
        return ("%");
    default:
        return (output3(format, ap, flags));
    }
}

char *output1(const char *format, va_list ap, int *flags)
{
    char *dest = "\0";
    switch (format[0]) {
    case 'u':
        return (my_ull_to_str(va_arg(ap, unsigned long long)));
    case 'o':
        dest = (flags[0] == 1) ? "0" : dest;
        return (my_strcat(dest, convert("01234567", 
        va_arg(ap, unsigned long long))));
    case 'x':
        dest = (flags[0] == 1) ? "0x" : dest;
        return (my_strcat(dest, convert("0123456789abcdef", 
        va_arg(ap, unsigned long long))));
    case 'X':
        dest = (flags[0] == 1) ? "0X" : dest;
        return (my_strcat(dest, convert("0123456789ABCDEF", 
        va_arg(ap, unsigned long long))));
    default:
        return (output2(format, ap, flags));
    }
}