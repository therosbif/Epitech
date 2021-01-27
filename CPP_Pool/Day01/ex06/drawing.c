/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD01-jack.goodall
** File description:
** drawing
*/

#include "drawing.h"
#include "bitmap.h"
#include <stdio.h>

void draw_square(uint32_t **img,
    const point_t *origin, size_t size, uint32_t color)
{
    for (size_t x = 0; x < size; x++) {
        for (size_t y = 0; y < size; y++)
            img[origin->x + x][origin->y + y] = color;
    }
}
