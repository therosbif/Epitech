/*
** EPITECH PROJECT, 2019
** CGP_my_screensaver_bootstrap_2019
** File description:
** polygone
*/

#include "framebuffer.h"

void draw_edge(framebuffer_t *fb, points_t *p, measure_t measure, sfColor color)
{
    sfVector2i curr;
    double x = 0;
    double y = 0;

    for (int i = 0; i < measure.cote; i++) {
        x += cos(measure.angle);
        y += sin(measure.angle);
        curr.x = (*p).point_a1.x + x;
        curr.y = (*p).point_a1.y + y;
        if (curr.x > 0 && curr.y > 0 && curr.x < 1919 && curr.y < 1079)
            my_put_pixel(fb, curr.x, curr.y, color);
    }
    (*p).point_a1.x = curr.x;
    (*p).point_a1.y = curr.y;
}

void shapes(framebuffer_t *fb, points_t *pts, int sides)
{
    measure_t measure;
    sfColor color = random_color();

    measure.angle = (double) (rand() % 35 / 2);
    measure.cote = rand() % 150 + 30;
    for (int i = 0; i < sides; i++) {
        draw_edge(fb, pts, measure, color);
        measure.angle += (double) 2 * 3.1415926535 / (double) sides;
    }
}