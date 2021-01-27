/*
** EPITECH PROJECT, 2019
** CGP_my_screensaver_bootstrap_2019
** File description:
** framebuffer
*/

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

#include <SFML/Graphics.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};

typedef struct framebuffer framebuffer_t;

typedef struct points {
    sfVector2i point_a1;
    sfVector2i point_b1;
    sfVector2i point_a2;
    sfVector2i point_b2;
    sfVector2i point_a3;
    sfVector2i point_b3;
} points_t;

typedef struct prev_dir {
    int d1;
    int d2;
    int d3;
} prev_dir_t;

typedef struct measure {
    double angle;
    int cote;
} measure_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);

void framebuffer_destroy(framebuffer_t *framebuffer);

void my_put_pixel
(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color);

void framebuffer_drawSquare
(framebuffer_t *framebuffer, unsigned int c, sfColor *color);

void draw_line(framebuffer_t *framebuffer,
sfVector2i point_a, sfVector2i point_b, sfColor color);

void draw_pipe(framebuffer_t *framebuffer,
sfVector2i pa, sfVector2i pb, sfColor color);

points_t init_struct(void);

prev_dir_t init_prev(void);

prev_dir_t pipes(framebuffer_t *fb, points_t *pts, prev_dir_t p_dir);

int draw_random(sfVector2i *point_a, sfVector2i *point_b, int prev_dir);

void shapes(framebuffer_t *fb, points_t *pts, int sides);

void draw_edge(framebuffer_t *fb, points_t *p, measure_t measure,
sfColor color);

sfColor random_color(void);

#endif /* !FRAMEBUFFER_H_ */