/*
** EPITECH PROJECT, 2019
** tetris.h
** File description:
** main
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include "c_tools.h"

#define HELP " [options]\nOptions:\n --help               Disp\
lay this help\n -L --level={num}     Start Tetris at level num (def: 1)\n -l --\
key-left={K}    Move the tetrimino LEFT using the K key (def: left arrow)\n -\
r --key-right={K}   Move the tetrimino RIGHT using the K key (def: right arrow\
)\n -t --key-turn={K}    TURN the tetrimino clockwise 90d using the K key (def\
: top arrow)\n -d --key-drop={K}    DROP the tetrimino using the K key (def: \
down arrow)\n -q --key-quit={K}    QUIT the game using the K key (def: \'q\' \
key)\n -p --key-pause ={K}  PAUSE/RESTART the game using the K key (def: spac\
e bar)\n --map-size={row,col} Set the numbers of rows and columns of the map \
(def: 20,10)\n -w --without-next    Hide next tetrimino (def: false)\n -D --de\
bug           Debug mode (def: false)\n"

#define WINDOW_LAYOUT "\
    -----   ----  -----   ---   -----   ----  \n\
      |    |        |    |   |    |    |      \n\
      |    |--      |    |--      |     ---   \n\
      |    |        |    |   |    |        |  \n\
      |     ----    |    |   |  -----  ----   \n\
                                              \n\
    +-----------------------------------+     \n\
    | High Score                        |     \n\
    | Score                             |     \n\
    |                                   |     \n\
    | Lines                             |     \n\
    | Level                             |     \n\
    |                                   |     \n\
    | Timer                             |     \n\
    +-----------------------------------+     \n\
     +-next----+                              \n\
     |         |                              \n\
     |         |                              \n\
     +---------+                              \n\
                                              \n"

#define GRID_OFFSET_X 43
#define GRID_OFFSET_Y 1

typedef struct game_info {
    int high_score;
    int score;
    int lines;
    int timer;
} game_info_t;
typedef struct vector2i {
    int x;
    int y;
} vector2i;

typedef struct settings {
    int level;
    int key_left;
    int key_right;
    int key_turn;
    int key_drop;
    int key_quit;
    int key_pause;
    vector2i map_size;
    int without_next;
    int debug;
} settings_t;

typedef struct tetrimino {
    int color;
    vector2i dim;
    vector2i pos;
    char *shape;
    struct tetrimino *next;
} tetrimino_t;

#define LONG_OPTS {{"help", 0, NULL, 'h'},\
{"level", 1, NULL, 'L'},\
{"key-left", 1, NULL, 'l'},\
{"key-right", 1, NULL, 'r'},\
{"key-turn", 1, NULL, 't'},\
{"key-drop", 1, NULL, 'd'},\
{"key-quit", 1, NULL, 'q'},\
{"key-pause", 1, NULL, 'p'},\
{"map-size", 1, NULL, 'm'},\
{"without-next", 0, NULL, 'w'},\
{"debug", 0, NULL, 'D'},\
{0, 0, 0, 0}}

void print_help(settings_t *settings, char *arg);
void init_curse(void);
void debug_mode(settings_t *flags);
settings_t *getflags(int ac, char **av);
void print_tetrimino_name(char *file_name);
void print_tetrimino_fline_info(char *file_name);
void print_tetrimino(char *file_name);
void tetris(settings_t *flags);
tetrimino_t *create_tetrimino(const char file_name[256]);
void add_tetrimino(tetrimino_t **list, tetrimino_t *tetrimino);
tetrimino_t *create_default_list(void);
int list_len(tetrimino_t *list);
int mv_rect(vector2i pos, vector2i offset, tetrimino_t *tetrimino);
tetrimino_t *cycle(tetrimino_t *in_play, tetrimino_t *pieces, int nb);
void free_list(tetrimino_t *list, int recur);
void draw_window(settings_t *flags);
unsigned int get_delay(int level);
void remove_line(settings_t *flags, game_info_t *game_info);
void game_over(game_info_t *game_info,
tetrimino_t *pieces, tetrimino_t *in_play);
void display_game_info(game_info_t *game_info, settings_t *flags);
game_info_t *set_game_info(void);
char *int_to_str(int i);
int handle_input(tetrimino_t *tetrimino, settings_t *flags);
void rotate(tetrimino_t *tetrimino);

#endif
