/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** remove_tabs
*/

#include "mysh.h"

char *remove_tabs(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\t')
            str[i] = ' ';
    }
    return str;
}

char *skip_spaces(char *str)
{
    while (*str == ' ') str++;
    return str;
}
