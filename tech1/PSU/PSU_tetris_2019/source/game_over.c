/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game_over
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>
#include "tetris.h"

void set_high_score(game_info_t *game_info)
{
    int fd = open("./high_score", O_CREAT);
    char *new_high = int_to_str(game_info->score);

    write(fd, new_high, my_strlen(new_high));
    write(fd, "\n", 1);
    close(fd);
    free(new_high);
}

void game_over(game_info_t *game_info,
tetrimino_t *pieces, tetrimino_t *in_play)
{
    int x = 0;
    int y = 0;

    if (game_info->score > game_info->high_score)
        set_high_score(game_info);
    getmaxyx(stdscr, y, x);
    clear();
    mvprintw(y / 2, x / 2, "GAME OVER\n");
    mvprintw(y / 2 + 2, x / 2, "High Score: %d\n", game_info->high_score);
    mvprintw(y / 2 + 3, x / 2, "Score: %d\n", game_info->score);
    refresh();
    sleep(3);
    free_list(pieces, 1);
    free_list(in_play, 0);
    free(game_info);
    endwin();
}
