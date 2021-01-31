/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** draw_window
*/

#include <ncurses.h>
#include "tetris.h"

void draw_window(settings_t *flags)
{
    int y = GRID_OFFSET_Y - 1;
    int x = GRID_OFFSET_X - 1;

    for (; y <= flags->map_size.y + 1; y++) {
        for (x = GRID_OFFSET_X - 1; x <= GRID_OFFSET_X + flags->map_size.x;){
            if (x == GRID_OFFSET_X - 1 ||
            x == GRID_OFFSET_X + flags->map_size.x)
                mvaddch(y, x, '|');
            else
                mvaddch(y, x, (!y || y == flags->map_size.y + 1) ? '-' : ' ');
            x++;
        }
    }
    mvaddch(GRID_OFFSET_Y - 1, GRID_OFFSET_X - 1, '+');
    mvaddch(GRID_OFFSET_Y - 1, GRID_OFFSET_X + flags->map_size.x, '+');
    mvaddch(flags->map_size.y + 1, GRID_OFFSET_X - 1, '+');
    mvaddch(flags->map_size.y + 1, GRID_OFFSET_X + flags->map_size.x, '+');
}
