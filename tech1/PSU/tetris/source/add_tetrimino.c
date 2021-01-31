/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** add_tetrimino.c
*/

#include "tetris.h"

void add_tetrimino(tetrimino_t **list, tetrimino_t *tetrimino)
{
    tetrimino->next = *list;
    *list = tetrimino;
}