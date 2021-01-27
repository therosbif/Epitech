/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_strlen_dellim
*/

#include "my.h"

int my_strlen_delim(char *str, char delim)
{
    int i = 0;

    for (; str && str[i] && str[i] != delim; i++);
    return i;
}
