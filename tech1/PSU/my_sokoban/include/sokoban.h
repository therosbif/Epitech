/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** sokoban
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct pos {
    int x;
    int y;
} pos_t;

#define MOVE_ARGS pos_t *pos, int x1, int y1, char *map, char *floor_tile

int my_strlen(char const *str);
char *my_strcpy(char const *src);
int *getdim(char *map);
pos_t init_pos(char *map);
void map_error(char *map);
char *get_map(int ac, char **av);
pos_t get_dim(char *map);
void resize_msg(pos_t max, char *map);
void initscreen(char *map);
char get_tile(int x, int y, char *map);
int check_lose(int max_x, int max_y);
int my_strcmp(char const *s1, char const *s2);

#endif /* !SOKOBAN_H_ */