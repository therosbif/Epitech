/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** get_flags
*/

#include <ncurses.h>
#include <getopt.h>
#include "tetris.h"

vector2i get_mapsize(char *arg, settings_t *settings)
{
    vector2i size;
    int i = 0;

    size.y = my_atoi(arg);
    while (arg[i] && arg[i] != ',') i++;
    if (!arg[i]) {
        free(settings);
        my_error("Error: invalid arg for --map-size.\n");
    }
    i++;
    size.x = my_atoi(arg + i);
    return size;
}

void tests(settings_t *settings, int c, char *arg)
{
    (c == 'h') ? print_help(settings, arg) : 1;
    (c == 'L') ? settings->level = *optarg : 1;
    (c == 'l') ? settings->key_left = *optarg : 1;
    (c == 'r') ? settings->key_right = *optarg : 1;
    (c == 'd') ? settings->key_drop = *optarg : 1;
    (c == 't') ? settings->key_turn = *optarg : 1;
    (c == 'q') ? settings->key_quit = *optarg : 1;
    (c == 'p') ? settings->key_pause = *optarg : 1;
    (c == 'm') ? settings->map_size = get_mapsize(optarg, settings)
    : (vector2i) {0, 0};
    (c == 'w') ? settings->without_next = 1 : 1;
    (c == 'D') ? settings->debug = 1 : 1;
    (c == ':') ? free(settings), my_error("Error: missing args.\n") : 1;
    (c == '?') ? free(settings), my_error("Error: invalid option.\n") : 1;
}

settings_t *create_default_settings(void)
{
    settings_t *settings = malloc(sizeof(settings_t));

    settings->debug = 0;
    settings->key_drop = KEY_DOWN;
    settings->key_left = KEY_LEFT;
    settings->key_right = KEY_RIGHT;
    settings->key_quit = 'q';
    settings->key_pause = ' ';
    settings->key_turn = KEY_UP;
    settings->without_next = 0;
    settings->level = 1;
    settings->map_size = (vector2i){20, 10};
    return settings;
}

settings_t *getflags(int ac, char **av)
{
    settings_t *settings = create_default_settings();
    int option_index = 0;
    const char *optstring = "L:l:r:t:d:q:p:wD";
    static struct option longopts[] = LONG_OPTS;
    int c = getopt_long(ac, av, optstring, longopts, &option_index);

    while (c != -1) {
        tests(settings, c, av[0]);
        c = getopt_long(ac, av, optstring, longopts, &option_index);
    }
    return settings;
}
