/*
** EPITECH PROJECT, 2019
** fractals
** File description:
** main
*/

#include "fractals.h"

int main(int ac, char **av)
{
    char **shape = NULL;
    char **shape_empty = NULL;
    mask_t masks;

    if (my_error(ac, av)) return 84;
    if (my_atoi(av[1]) == 0) return write(1, "#\n", 2);
    masks.mask = create_shape(av[2]);
    masks.mask_empty = create_shape(av[3]);
    shape = create_shape(av[2]);
    shape_empty = create_shape(av[3]);
    shape = fractals(shape, shape_empty, masks, my_atoi(av[1]));
    for (int i = 0; shape[i]; i++){
        my_putstr(shape[i]);
        write(1, "\n", 1);
    }
    free_arr(shape);
    free_arr(masks.mask);
    free_arr(masks.mask_empty);
    return 0;
}
