/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_tetrimino_size.c
*/

#include <stdio.h>
#include "c_tools.h"

int check_line(char *line)
{
    if (my_strlen(line) != 6)
        return 0;
    if (line[1] != ' ' || line[3] != ' ')
        return 0;
    if (line[0] > '4' || line[0] < '0' || line[2] > '4' || line[2] < '0')
        return 0;
    if (line[4] < '0' || line[4] > '7')
        return 0;
    return 1;
}

void print_tetrimino_fline_info(char *file_name)
{
    char *abs_path = my_strcat("tetriminos/", file_name);
    FILE *tetrimino_file = fopen(abs_path, "r");
    char *line = NULL;
    size_t size = 0;

    getline(&line, &size, tetrimino_file);
    if (!check_line(line)) {
        my_putstr("Error");
        free(line);
        return;
    }
    my_putchar(line[0]);
    my_putchar('*');
    my_putchar(line[2]);
    my_putstr(" :  Color ");
    my_putchar(line[4]);
    my_putstr(" :\n");
    free(abs_path);
    free(line);
    fclose(tetrimino_file);
}