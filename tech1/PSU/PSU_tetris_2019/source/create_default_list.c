/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** create_default_list.c
*/

#include "tetris.h"
#include <stdio.h>
#include <dirent.h>

tetrimino_t *create_default_list(void)
{
    DIR *dir = opendir("./tetriminos");
    struct dirent *file_info = readdir(dir);
    tetrimino_t *tetrimino_list = NULL;

    for (; file_info; file_info = readdir(dir)) {
        if (file_info->d_name[0] == '.')
            continue;
        add_tetrimino(&tetrimino_list, create_tetrimino(file_info->d_name));
    }
    closedir(dir);
    return tetrimino_list;
}
