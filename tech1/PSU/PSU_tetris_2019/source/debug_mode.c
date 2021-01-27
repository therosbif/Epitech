/*
** EPITECH PROJECT, 2020
** source/debug_mode
** File description:
** debug_mode
*/

#include "tetris.h"
#include "c_tools.h"
#include <sys/types.h>
#include <dirent.h>
#include <ncurses.h>
#include <stdio.h>
#include <string.h>

void print_key(int key)
{
    switch (key) {
        case KEY_LEFT: my_putstr("^EOD");
            break;
        case KEY_RIGHT: my_putstr("^EOC");
            break;
        case KEY_UP: my_putstr("^EOA");
            break;
        case KEY_DOWN: my_putstr("^EOB");
            break;
        case ' ': my_putstr("(space)");
            break;
        default: my_putchar(key);
    }
    my_putchar('\n');
}

void print_game_infos(settings_t *flags)
{
    my_putstr("Key Left :  "), print_key(flags->key_left);
    my_putstr("Key Right :  "), print_key(flags->key_right);
    my_putstr("Key Turn :  "), print_key(flags->key_turn);
    my_putstr("Key Drop :  "), print_key(flags->key_drop);
    my_putstr("Key Quit :  "), print_key(flags->key_quit);
    my_putstr("Key Pause :  "), print_key(flags->key_pause);
    my_putstr("Next :  "), my_putstr((flags->without_next) ? "No\n" : "Yes\n");
    my_putstr("Level :  "), my_put_nbr(flags->level), my_putchar('\n');
    my_putstr("Size :  "), my_put_nbr(flags->map_size.x), my_putchar('*');
    my_put_nbr(flags->map_size.y), my_putchar('\n');
}

void print_tetriminos_info(void)
{
    DIR *tetriminos_dir = opendir("./tetriminos");
    struct dirent *dir_info = readdir(tetriminos_dir);
    int nb_tetro = 0;

    for (; dir_info; dir_info = readdir(tetriminos_dir))
        nb_tetro = (dir_info->d_name[0] == '.') ? nb_tetro + 1 : nb_tetro;
    closedir(tetriminos_dir);
    my_putstr("Tetriminos :  "), my_put_nbr(nb_tetro);
    tetriminos_dir = opendir("./tetriminos");
    dir_info = readdir(tetriminos_dir);
    while (dir_info) {
        if (dir_info->d_name[0] != '.') {
            my_putstr("\nTetriminos :  Name ");
            print_tetrimino_name(dir_info->d_name);
            print_tetrimino_fline_info(dir_info->d_name);
            print_tetrimino(dir_info->d_name);
        }
        dir_info = readdir(tetriminos_dir);
    }
    closedir(tetriminos_dir);
}

void debug_mode(settings_t *flags)
{
    my_putstr("*** DEBUG MODE ***\n");
    print_game_infos(flags);
    print_tetriminos_info();
    my_putstr("Press any key to start Tetris\n");
}
