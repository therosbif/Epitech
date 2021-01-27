/*
** EPITECH PROJECT, 2020
** minishell2_tmp
** File description:
** get_next
*/

#include "mysh.h"

char *get_next(char *line, char c)
{
    char *tmp = line;

    while (*tmp && *tmp != c) tmp++;
    if (*tmp) {
        *tmp = 0;
        return my_strdup(tmp + 1);
    } else
        return NULL;
}
