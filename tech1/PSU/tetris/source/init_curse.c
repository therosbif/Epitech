/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** init_curse.c
*/

#include <ncurses.h>
#include "tetris.h"

void init_curse(void)
{
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, true);
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    printw(WINDOW_LAYOUT);
}
