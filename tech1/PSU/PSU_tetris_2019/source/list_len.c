/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** list_len
*/

#include "tetris.h"

int list_len(tetrimino_t *list)
{
    int i = 0;

    for (; list; i++, list = list->next);
    return i;
}
