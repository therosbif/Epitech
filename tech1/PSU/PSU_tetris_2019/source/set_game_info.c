/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** set_game_info
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "tetris.h"

game_info_t *set_game_info(void)
{
    game_info_t *game_info = malloc(sizeof(game_info_t));
    FILE *file = fopen("./high_score", "r");
    char *buff;
    size_t n = 0;

    getline(&buff, &n, file);
    game_info->lines = 0;
    game_info->score = 0;
    game_info->timer = 0;
    game_info->high_score = my_atoi(buff);
    free(buff);
    fclose(file);
    return game_info;
}
