/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_help.c
*/

#include "tetris.h"
#include <stdlib.h>

void print_help(settings_t *settings, char *arg)
{
    my_putstr("Usage:  ");
    my_putstr(arg),
    my_putstr(HELP);
    free(settings);
    exit(84);
}
