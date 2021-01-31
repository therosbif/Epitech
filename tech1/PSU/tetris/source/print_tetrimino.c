/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_tetrimino.c
*/

#include "c_tools.h"
#include <sys/fcntl.h>

void print_tetrimino(char *file_name)
{
    char *abs_path = my_strcat("tetriminos/", file_name);
    int fd = open(abs_path, O_RDONLY);
    long fsize = 0;
    char *buffer = NULL;

    if (fd == -1) {
        free(abs_path);
        return;
    }
    fsize = lseek(fd, 0, SEEK_END) - 6;
    buffer = malloc(fsize + 1);
    buffer[fsize] = 0;
    lseek(fd, 6, SEEK_SET);
    read(fd, buffer, fsize);
    my_putstr(buffer);
    close(fd);
    free(buffer);
    free(abs_path);
}
