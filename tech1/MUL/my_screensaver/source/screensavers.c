/*
** EPITECH PROJECT, 2019
** CGP_my_screensaver_bootstrap_2019
** File description:
** screensavers
*/

#include <stdlib.h>
#include "framebuffer.h"

sfVector2i init_point(void)
{
    sfVector2i point;

    point.x = 900;
    point.y = 500;
    return point;
}

points_t init_struct(void)
{
    points_t points;

    points.point_a1 = init_point();
    points.point_b1 = init_point();
    points.point_a2 = init_point();
    points.point_b2 = init_point();
    points.point_a3 = init_point();
    points.point_b3 = init_point();
    return points;
}

prev_dir_t init_prev(void)
{
    prev_dir_t prev_dir;

    prev_dir.d1 = 1;
    prev_dir.d2 = 1;
    prev_dir.d3 = 1;
    return prev_dir;
}

prev_dir_t pipes(framebuffer_t *fb, points_t *pts, prev_dir_t p_dir)
{
    draw_line(fb, (*pts).point_a1, (*pts).point_b1, sfRed);
    draw_line(fb, (*pts).point_a2, (*pts).point_b2, sfYellow);
    draw_line(fb, (*pts).point_a3, (*pts).point_b3, sfGreen);
    p_dir.d1 = draw_random(&((*pts).point_a1), &((*pts).point_b1), p_dir.d1);
    p_dir.d2 = draw_random(&((*pts).point_a2), &((*pts).point_b2), p_dir.d2);
    p_dir.d3 = draw_random(&((*pts).point_a3), &((*pts).point_b3), p_dir.d3);
    return p_dir;
}