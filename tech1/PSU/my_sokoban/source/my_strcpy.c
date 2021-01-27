/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copy str
*/

#include <stdlib.h>
#include "sokoban.h"

char *my_strcpy(char const *src)
{
    int i = 0;
    char *dest = malloc(my_strlen(src));

    for ( ; src[i] != '\0' ; i++)
        dest[i] = src[i];
    dest[i] = 0;
    return (dest);
}

void initscreen(char *map)
{
    initscr();
    map_error(map);
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    printw(map);
}

char get_tile(int x, int y, char *map)
{
    for (int i = 0; i < y; map++) {
        if (*map == '\n')
            i++;
    }
    for (; x; x--, map++);
    return ((*map == 'O') ? 'O' : ' ');
}

int check_lose(int max_x, int max_y)
{
    for (int y = 0; y < max_y; y++) {
        for (int x = 0; x < max_x; x++) {
            if (mvinch(y, x) == 'X' && ((mvinch(y, x + 1) != '#' &&
            mvinch(y, x + 1) != 'X' && mvinch(y, x - 1) != '#' &&
            mvinch(y, x - 1) != 'X') || (mvinch(y + 1, x) != '#' &&
            mvinch(y + 1, x) != 'X' && mvinch(y - 1, x) != '#' &&
            mvinch(y - 1, x) != 'X')))
                return 0;
        }
    }
    return 1;
}