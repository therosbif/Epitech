/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** cycle
*/

#include "tetris.h"
#include <time.h>

void copy_contents(tetrimino_t *in_play, tetrimino_t *pieces)
{
    in_play->color = pieces->color;
    in_play->dim = pieces->dim;
    in_play->pos.x = 0;
    in_play->pos.y = 0;
    in_play->shape = pieces->shape;
}

tetrimino_t *cycle(tetrimino_t *in_play, tetrimino_t *pieces, int nb)
{
    tetrimino_t *tmp = in_play;
    tetrimino_t *begin = pieces;
    int select = 0;

    srand(time(NULL));
    select = rand() % nb;
    for (int i = 0; i < select; i++, pieces = pieces->next);
    if (in_play && in_play->next) {
        in_play = in_play->next;
        in_play->next = malloc(sizeof(tetrimino_t));
        free(tmp), copy_contents(in_play, pieces);
    } else {
        copy_contents(in_play, pieces);
        in_play->next = malloc(sizeof(tetrimino_t));
        pieces = begin;
        select = rand() % nb;
        for (int i = 0; i < select; i++, pieces = pieces->next);
        copy_contents(in_play->next, pieces);
        in_play->next->next = NULL;
    }
    return in_play;
}
