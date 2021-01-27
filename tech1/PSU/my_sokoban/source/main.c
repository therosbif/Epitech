/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** main
*/

#include "sokoban.h"

int check_win(int max_x, int max_y, char *floor_tile)
{
    for (int x = 0; x < max_x; x++){
        for (int y = 0; y < max_y; y++) {
            if (mvinch(y, x) == 'O')
                return 0;
        }
    }
    return ((*floor_tile == ' ') ? 1 : 0);
}

int move_to(MOVE_ARGS)
{
    char dest = mvinch(y1, x1);

    if (dest == ' ' || dest == 'O') {
        mvaddch(pos->y, pos->x, get_tile(pos->x, pos->y, map));
        mvaddch(y1, x1, 'P');
        *floor_tile = dest;
        return 1;
    } else if (dest == 88 && mvinch(y1 + y1 - pos->y, x1 + x1 - pos->x) != '#'
        && mvinch(y1 + y1 - pos->y, x1 + x1 - pos->x) != 'X'){
        mvaddch(pos->y, pos->x, get_tile(pos->x, pos->y, map));
        mvaddch(y1, x1, 'P');
        mvaddch(y1 + (y1 - pos->y), x1 + (x1 - pos->x), 'X');
        return 1;
    }
    return 0;
}

void update_map(pos_t *pos, int key, char *map, char *floor_tile)
{
    switch (key) {
    case KEY_RIGHT:
        (move_to(pos, pos->x + 1, pos->y, map, floor_tile)) ? pos->x++ : 1;
        break;
    case KEY_LEFT:
        (move_to(pos, pos->x - 1, pos->y, map, floor_tile)) ? pos->x-- : 1;
        break;
    case KEY_UP:
        (move_to(pos, pos->x, pos->y - 1, map, floor_tile)) ? pos->y-- : 1;
        break;
    case KEY_DOWN:
        (move_to(pos, pos->x, pos->y + 1, map, floor_tile)) ? pos->y++ : 1;
        break;
    }
}

int game_loop(char *map, pos_t max, pos_t dim, pos_t *pos)
{
    int key = getch();
    char floor_tile = ' ';

    getmaxyx(stdscr, max.y, max.x);
    while (max.x < dim.x || max.y < dim.y) {
        getmaxyx(stdscr, max.y, max.x);
        resize_msg(max, map);
        *pos = init_pos(map);
    }
    if (key == ' ') {
        clear();
        printw(map);
        *pos = init_pos(map);
    }
    update_map(pos, key, map, &floor_tile);
    refresh();
    (check_lose(max.x, max.y) && !check_win(max.y, max.x, &floor_tile)) ?
    endwin(), exit(1) : 0;
    return (check_win(max.y, max.x, &floor_tile)) ? 1 : 0;
}

int main(int ac, char ** av)
{
    char *map = get_map(ac, av);
    pos_t max = {0, 0};
    pos_t dim = get_dim(map);
    pos_t pos = init_pos(map);

    initscreen(map);
    while (1) {
        if (game_loop(map, max, dim, &pos))
            break;
    }
    endwin();
    return 0;
}