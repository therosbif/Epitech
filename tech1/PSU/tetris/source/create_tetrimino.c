/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** create_tetrimino.c
*/

#include "tetris.h"
#include <sys/fcntl.h>

void get_tetriminio_info(int fd, tetrimino_t *tetrimino)
{
    char first_line[6] = {0, 0, 0, 0, 0, 0};

    read(fd, first_line, 6);
    tetrimino->dim.x = first_line[0] - 48;
    tetrimino->dim.y = first_line[2] - 48;
    tetrimino->color = first_line[4] - 48;
}

tetrimino_t *create_tetrimino(const char file_name[256])
{
    tetrimino_t *tetrimino = malloc(sizeof(*tetrimino));
    char *abs_path = my_strcat("tetriminos/", file_name);
    int fd = open(abs_path, O_RDONLY);
    long fsize = 0;

    get_tetriminio_info(fd, tetrimino);
    fsize = lseek(fd, 0, SEEK_END) - 6;
    tetrimino->shape = malloc(fsize + 1);
    lseek(fd, 6, SEEK_SET);
    read(fd, tetrimino->shape, fsize);
    tetrimino->shape[fsize] = 0;
    tetrimino->pos = (vector2i){0, 0};
    tetrimino->next = NULL;
    close(fd);
    free(abs_path);
    return tetrimino;
}