/*
** EPITECH PROJECT, 2019
** CGP_my_screensaver_bootstrap_2019
** File description:
** framebuffer
*/

#include <SFML/Graphics.h>
//#include <SFML/Window.h>
//#include <SFML/System.h>
//#include <SFML/Audio.h>
#include <stdlib.h>
#include "framebuffer.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *buff = malloc(sizeof(framebuffer_t));

    buff->width = width;
    buff->height = height;
    buff->pixels = malloc(width * height * 4);
    return buff;
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}

void my_put_pixel
(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color)
{
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 0] = color.r;
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 1] = color.g;
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 2] = color.b;
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 3] = color.a;
}