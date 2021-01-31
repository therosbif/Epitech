/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_tetrimino_name.c
*/

#include "c_tools.h"

void print_tetrimino_name(char *file_name)
{
    while (*file_name != '.' && *file_name) {
        my_putchar(*file_name);
        file_name++;
    }
    my_putstr(" :  ");
}
