/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** standard_mode
*/

#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include "tetris.h"

int game_loop
(settings_t *flags, tetrimino_t **in_play, tetrimino_t * pieces, int nb)
{
    static clock_t previous = 0;
    clock_t elapsed_time = clock();
    float delay = get_delay(flags->level);
    int lost = -1;

    if (!handle_input(*in_play, flags))
        return 1;
    if ((float)(elapsed_time - previous) / (float)CLOCKS_PER_SEC >= delay) {
        previous = elapsed_time;
        if (!mv_rect((*in_play)->pos, (vector2i){0, 1}, *in_play)) {
            lost = (!(*in_play)->pos.y);
            *in_play = cycle(*in_play, pieces, nb);
            return lost;
        }
        (*in_play)->pos.y++;
    }
    refresh();
    return 0;
}

void tetris(settings_t *flags)
{
    tetrimino_t *pieces = create_default_list();
    tetrimino_t *in_play = malloc(sizeof(tetrimino_t));
    game_info_t *game_info = set_game_info();
    int nb = list_len(pieces);
    int event = 0;

    in_play->next = NULL;
    in_play = cycle(in_play, pieces, nb);
    init_curse();
    draw_window(flags);
    while (1) {
        display_game_info(game_info, flags);
        if (in_play->pos.y == 0)
            mv_rect(in_play->pos, (vector2i){0, 0}, in_play);
        event = game_loop(flags, &in_play, pieces, nb);
        if (event == 1)
            break;
        remove_line(flags, game_info);
    }
    game_over(game_info, pieces, in_play);
}
