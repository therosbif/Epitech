/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** mv_rect.c
*/

#include "tetris.h"
#include <ncurses.h>
#include <sys/fcntl.h>

static void remove_char(vector2i pos, vector2i rel_pos, tetrimino_t *tetrimino)
{
    int array_pos = 0;

    for (int i = 0; i < rel_pos.y; i++)
        while (tetrimino->shape[array_pos++] != '\n');
    array_pos += rel_pos.x;
    if (tetrimino->shape[array_pos] != ' ')
        mvaddch(pos.y + GRID_OFFSET_Y, pos.x + GRID_OFFSET_X, ' ');
}

int is_placeable(int x, int y, vector2i rel_pos, tetrimino_t *tetrimino)
{
    int array_pos = 0;

    x += GRID_OFFSET_X;
    y += GRID_OFFSET_Y;
    for (int i = 0; i < rel_pos.y; i++)
        while (tetrimino->shape[array_pos++] != '\n');
    array_pos += rel_pos.x;
    if (tetrimino->shape[array_pos] == '*' && (mvinch(y, x) == '*' ||
        mvinch(y, x) == '|' || mvinch(y, x) == '-'))
        return 0;
    return 1;
}

void place_char(int x, int y, vector2i rel_pos, tetrimino_t *tetrimino)
{
    int array_pos = 0;

    for (int i = 0; i < rel_pos.y; i++)
        while (tetrimino->shape[array_pos++] != '\n');
    array_pos += rel_pos.x;
    if (tetrimino->shape[array_pos] == '*')
        mvaddch(y + GRID_OFFSET_Y, x + GRID_OFFSET_X, '*');
}

int mv_rect(vector2i pos, vector2i offset, tetrimino_t *tetrimino)
{
    int placeable = 1;

    for (int y = 0; y < tetrimino->dim.y; y++)
        for (int x = 0; x < tetrimino->dim.x; x++)
            remove_char((vector2i){pos.x + x, pos.y + y}, (vector2i){x, y},
            tetrimino);
    for (int y = 0; y < tetrimino->dim.y; y++)
        for (int x = 0; x < tetrimino->dim.x; x++)
            placeable = (placeable) ? is_placeable(pos.x + offset.x + x, pos.y +
            offset.y + y, (vector2i){x, y}, tetrimino) : 0;
    if (!placeable) {
        mv_rect(pos, (vector2i){0, 0}, tetrimino);
        return 0;
    }
    for (int y = 0; y < tetrimino->dim.y; y++)
        for (int x = 0; x < tetrimino->dim.x; x++)
            place_char(pos.x + offset.x + x, pos.y + offset.y + y, (vector2i)
            {x, y}, tetrimino);
    return 1;
}
