/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** int_to_str
*/

#include "c_tools.h"

char *int_to_str(int i)
{
    int len = my_nlen(i);
    char *str = malloc(len + 1);

    str[len] = 0;
    while (len) {
        str[--len] = i % 10 + 48;
        i /= 10;
    }
    return str;
}
