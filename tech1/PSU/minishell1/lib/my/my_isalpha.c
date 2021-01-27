/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include "mysh.h"

int my_isalpha(char c)
{
    if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z'))
        return 0;
    return 1;
}

int my_isdig(char c)
{
    if (!(c >= '0' && c <= '9'))
        return 0;
    return 1;
}

int my_isalphanum(char *str)
{
    for (; *str; str++) if (!my_isdig(*str) && !my_isalpha(*str)) return 0;
    return 1;
}
