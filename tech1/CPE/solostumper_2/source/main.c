/*
** EPITECH PROJECT, 2019
** rostring
** File description:
** main
*/

#include "rostring.h"

void show_words(char *ptr)
{
    int final_space = 0;

    for (; *ptr; ptr++) {
        final_space = 1;
        if (!((*ptr == ' ' || *ptr == '\t') &&
            (*(ptr + 1) == ' ' || *(ptr + 1) == '\t' || !*(ptr + 1))))
            write(1, ptr, 1);
    }
    if (final_space)
        write(1, " ", 1);
}

int main(int ac, char **av)
{
    char *ptr = ((ac == 2) ? av[1] : NULL);
    char *str = ((ac == 2) ? av[1] : NULL);

    if (ac < 2)
        return 0;
    else if (ac > 2)
        return 84;
    for (; *ptr == ' ' || *ptr == '\t'; ptr++, str++);
    for (; *ptr && *ptr != ' ' && *ptr != '\t'; ptr++);
    if (*ptr)
        *ptr++ = 0;
    for (; *ptr && (*ptr == ' ' || *ptr == '\t'); ptr++);
    show_words(ptr);
    for (; *str; str++)
        write(1, str, 1);
    write(1, "\n", 1);
    return 0;
}

