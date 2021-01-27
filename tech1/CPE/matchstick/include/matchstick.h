/*
** EPITECH PROJECT, 2019
** matchstick.h
** File description:
** main
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

#define MAX(a, b) ((a >= b) ? a : b)
#define MIN(a, b) ((a <= b) ? a : b)
#define ERR_RANGE  "Error: this line is out of range\n"
#define ERR_INV "Error: invalid input (positive number expected)\n"
#define ERR_MINMATCH "Error: you have to remove at least one match\n"
#define ERR_TOTALMATCH "Error: not enough matches on this line\n"
#define ERR_NLINES "ERROR: number of lines must be strictly between 1 and 100\n"
#define MSG_WIN "I lost... snif... but I'll get you next time!!\n"
#define MSG_LOSE "You lost, too bad...\n"

char **make_map(char **map, int lines);
void show_map(char **map, int lines);
int game_loop(char **map, int lines, int max);
char **remove_matches(int *coords, char **map);
int count_match(char *line);
int *pick_coords(int max, int *coords, char **map);
int nb_error(int nb, int total, int max);
void disp_pick(int *coords, int turn);

#endif
