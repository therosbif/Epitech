/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_strdup_dellim
*/

#include "my.h"

char *my_strdup_delim(char *str, char delim)
{
    int len = my_strlen_delim(str, delim);
    char *dest = malloc(len + 2);
    int i = 0;

    for (; i < len; i++) dest[i] = str[i];
    dest[i] = '/';
    dest[i + 1] = 0;
    return dest;
}
