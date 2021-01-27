/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** rotate.c
*/

#include "tetris.h"
#include <ncurses.h>
#include <unistd.h>

static void remove_char(vector2i pos, vector2i rel_pos, tetrimino_t *tetrimino)
{
    int array_pos = 0;

    for (int i = 0; i < rel_pos.y; i++)
        while (tetrimino->shape[array_pos++] != '\n');
    array_pos += rel_pos.x;
    if (tetrimino->shape[array_pos] != ' ')
        mvaddch(pos.y + GRID_OFFSET_Y, pos.x + GRID_OFFSET_X, ' ');
}

void remove_tetrimino(tetrimino_t *tetrimino)
{
    for (int y = 0; y < tetrimino->dim.y; y++)
        for (int x = 0; x < tetrimino->dim.x; x++)
            remove_char((vector2i){tetrimino->pos.x + x, tetrimino->pos.y + y},
            (vector2i){x, y}, tetrimino);
}

void rotate(tetrimino_t *tetrimino)
{
    return;
}
