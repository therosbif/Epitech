/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** remove_line
*/

#include <ncurses.h>
#include "tetris.h"

void delete_line(settings_t *flags, int y)
{
    for (; y > 1; y--)
        for (int x = 43; x < flags->map_size.x + 43; x++)
            mvaddch(y, x, mvinch(y - 1, x));
}

void remove_line(settings_t *flags, game_info_t *game_info)
{
    int cnt = 0;

    for (int y = GRID_OFFSET_Y; y <= flags->map_size.y; y++) {
        cnt = 0;
        for (int x = GRID_OFFSET_X; x <= 43 + flags->map_size.x; x++)
            cnt += (mvinch(y, x) == '*');
        if (cnt == flags->map_size.x) {
            delete_line(flags, y);
            game_info->score += 10;
            game_info->lines++;
        }
    }
}