/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include "fractals.h"

int my_arrlen(char **arr)
{
    int i = 0;

    for (; arr[i]; i++);
    return i;
}
