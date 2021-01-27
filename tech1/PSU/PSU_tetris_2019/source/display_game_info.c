/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_game_info
*/

#include <ncurses.h>
#include "tetris.h"
#include "c_tools.h"
#include <time.h>

void display_time(void)
{
    clock_t elapsed = clock() / CLOCKS_PER_SEC;
    char *minutes = base_conv(elapsed / 60.0f, 10, 'x');
    char *seconds = base_conv(elapsed % 60, 10, 'x');

    if (my_strlen(minutes) == 1 && my_strlen(seconds) == 1) {
        mvprintw(13, 24, "0%s:0%s", minutes, seconds);
        return;
    }
    if (my_strlen(minutes) == 2 && my_strlen(seconds) == 1)
        mvprintw(13, 24, "%s:0%s", minutes, seconds);
    else if (my_strlen(minutes) == 2 && my_strlen(seconds) == 2)
        mvprintw(13, 24, "%s:%s", minutes, seconds);
    else
        mvprintw(13, 24, "0%s:%s", minutes, seconds);
}

void display_game_info(game_info_t *game_info, settings_t *flags)
{
    char *str[4];

    str[0] = base_conv(game_info->high_score, 10, 'x');
    str[1] = base_conv(game_info->score, 10, 'x');
    str[2] = base_conv(game_info->lines, 10, 'x');
    str[3] = base_conv(flags->level, 10, 'x');
    mvprintw(7, 24, "%s", str[0]);
    mvprintw(8, 24, "%s", str[1]);
    mvprintw(10, 24,"%s", str[2]);
    mvprintw(11, 24, "%s", str[3]);
    display_time();
}
