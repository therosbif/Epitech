/*
** EPITECH PROJECT, 2019
** CGP_my_screensaver_bootstrap_2019
** File description:
** .
*/

#include "framebuffer.h"

sfColor random_color(void)
{
    int color = rand() % 7;

    switch (color) {
    case 0:
        return (sfWhite);
    case 1:
        return (sfRed);
    case 2:
        return (sfYellow);
    case 3:
        return (sfGreen);
    case 4:
        return (sfCyan);
    case 5:
        return (sfBlue);
    }
    return (sfMagenta);
}

void framebuffer_drawSquare
(framebuffer_t *framebuffer, unsigned int c, sfColor *color)
{
    for (unsigned int x = 0 ; x < c ; x++) {
        for (unsigned int y = 0 ; y < c ; y++)
            my_put_pixel(framebuffer, x, y, *color);
        }
}

void draw_line(framebuffer_t *framebuffer,
sfVector2i point_a, sfVector2i point_b, sfColor color)
{
    if (point_a.x == point_b.x) {
        if (point_a.y < point_b.y) {
            for (int y = point_a.y; y < point_b.y; y++)
                my_put_pixel(framebuffer, point_a.x, y, color);
        } else {
            for (int y = point_b.y; y < point_a.y; y++)
                my_put_pixel(framebuffer, point_a.x, y, color);
        }
    } else {
        if (point_a.x < point_b.x) {
            for (int x = point_a.x; x < point_b.x; x++)
                my_put_pixel(framebuffer, x, point_a.y, color);
        } else {
            for (int x = point_b.x; x < point_a.x; x++)
                my_put_pixel(framebuffer, x, point_a.y, color);
        }
    }
}

void draw_pipe(framebuffer_t *framebuffer,
sfVector2i pa, sfVector2i pb, sfColor color)
{
    int tmp = 0;

    draw_line(framebuffer, pa, pb, sfBlack);
    if (pa.x == pb.x) {
        tmp = (pa.x += 1) && (pb.x += 1);
        draw_line(framebuffer, pa, pb, color);
        tmp = (pa.x += 3) && (pb.x += 3);
        draw_line(framebuffer, pa, pb, color);
        tmp = (pa.x += 1) && (pb.x += 1);
        draw_line(framebuffer, pa, pb, sfBlack);
    } else {
        tmp = (pa.y += 1) && (pb.y += 1);
        draw_line(framebuffer, pa, pb, color);
        tmp = (pa.y += 3) && (pb.y += 3);
        draw_line(framebuffer, pa, pb, color);
        tmp = (pa.y += 1) && (pb.y += 1);
        draw_line(framebuffer, pa, pb, sfBlack);
    }
}