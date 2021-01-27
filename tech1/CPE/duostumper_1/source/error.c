/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include "fractals.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}

int my_strlen_delim(char *str, char delim)
{
    int i = 0;

    for (; str[i] && str[i] != delim; i++);
    return (i);
}

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

int my_error(int ac, char **av)
{
    if (ac != 4 || !is_int(av[1]))
        return 84;
    if (!is_valid_chars(av[2]) || !is_valid_chars(av[3]))
        return 84;
    if (my_strlen(av[2]) != my_strlen(av[3]))
        return 84;
    for (int i = 0; av[2][i]; i++) {
        if (av[2][i] == '@' && av[3][i] != '@')
            return 84;
    }
    return 0;
}

