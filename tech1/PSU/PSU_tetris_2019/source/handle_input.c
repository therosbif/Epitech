/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** handle_input.c
*/

#include "tetris.h"
#include <ncurses.h>
#include <unistd.h>

int strafe_keys(int input, tetrimino_t *tetrimino, settings_t *flags)
{
    if (input == flags->key_left) {
        if (mv_rect(tetrimino->pos, (vector2i){-1, 0}, tetrimino))
            tetrimino->pos.x--;
        refresh();
        return 1;
    }
    if (input == flags->key_right) {
        if (mv_rect(tetrimino->pos, (vector2i){1, 0}, tetrimino))
            tetrimino->pos.x++;
        refresh();
        return 1;
    }
    if (input == flags->key_drop) {
        if (mv_rect(tetrimino->pos, (vector2i){0, 1}, tetrimino))
            tetrimino->pos.y++;
        refresh();
        return 1;
    }
    return 0;
}

int handle_input(tetrimino_t *tetrimino, settings_t *flags)
{
    static int paused = 0;
    int input = getch();

    if (strafe_keys(input, tetrimino, flags))
        return 1;
    if (input == flags->key_quit) {
        return 0;
    }
    if (input == flags->key_pause) {
        usleep(50);
        while (getch() != flags->key_pause);
        return 1;
    }
    if (input == flags->key_turn) {
        rotate(tetrimino);
    }
    return 1;
}