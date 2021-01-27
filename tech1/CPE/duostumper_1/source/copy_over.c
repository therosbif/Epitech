/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include "fractals.h"

void copy_over(char **shape, char ***new_shape, int x, int y)
{
    x *= my_strlen(*shape);
    y *= my_arrlen(shape);
    for (int i = 0; i < my_arrlen(shape); i++) {
        for (int j = 0; j < my_strlen(*shape); j++) {
            (*new_shape)[y + i][x + j] = shape[i][j];
        }
    }
}

void empty_shape(char **shape, char ***new_shape, int x, int y)
{
    x *= my_strlen(*shape);
    y *= my_arrlen(shape);
    for (int i = 0; i < my_arrlen(shape); i++) {
        for (int j = 0; j < my_strlen(*shape); j++) {
            (*new_shape)[y + i][x + j] = '.';
        }
    }
}
