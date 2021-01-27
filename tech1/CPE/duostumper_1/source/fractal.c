/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include "fractals.h"

char **create_shape(char *str)
{
    int height = count_char_instr(str, '@') + 1;
    int width = my_strlen_delim(str, '@');
    char **table = malloc((height + 1) * sizeof(char *));

    table[height] = NULL;
    for (int i = 0; i < height; i++) {
        table[i] = malloc(width + 1);
        for (int j = 0; *str && *str != '@'; str++, j++)
            table[i][j] = *str;
        if (*str) str++;
        table[i][width] = 0;
    }
    return table;
}

char **scale_shape(char **shape, char **shape_empty, char **mask)
{
    int width = my_strlen(*shape) * my_strlen(*mask);
    int height = my_arrlen(shape) * my_arrlen(mask);
    char **new_shape = malloc((height + 1) * sizeof(char *));

    new_shape[height] = NULL;
    for (int i = 0; i < height; i++) {
        new_shape[i] = malloc(width + 1);
        new_shape[i][width] = 0;
    }
    for (int y = 0; mask[y]; y++) {
        for (int x = 0; mask[y][x]; x++) {
            if (mask[y][x] == '#')
                copy_over(shape, &new_shape, x, y);
            else
                copy_over(shape_empty, &new_shape, x, y);
        }
    }
    return new_shape;
}

char **fractals(char **shape, char **shape_empty, mask_t masks, int i)
{
    char **new_shape = scale_shape(shape, shape_empty, masks.mask);

    shape_empty = scale_shape(shape, shape_empty, masks.mask_empty);
    if (i > 1) {
        free_arr(shape);
        return fractals(new_shape, shape_empty, masks, i - 1);
    } else {
        free_arr(new_shape);
        return shape;
    }
}


