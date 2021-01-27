/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** free_lists
*/

#include "tetris.h"
#include <ncurses.h>

void free_list(tetrimino_t *list, int recur)
{
    tetrimino_t *tmp;

    for (int i = 0; i < 2; i++) {
        tmp = list;
        list = list->next;
        if (recur)
            free(tmp->shape);
        free(tmp);
    }
}
