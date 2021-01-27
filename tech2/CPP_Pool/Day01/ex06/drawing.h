/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD01-jack.goodall
** File description:
** drawing
*/

#ifndef DRAWING_H_
#define DRAWING_H_

#include <stdint.h>
#include <stdlib.h>

void write_bmp_info_header(int fd, size_t size);
void write_bmp_header(int fd, size_t size);

typedef struct point {
    unsigned int x;
    unsigned int y;
} point_t;

void draw_square(uint32_t **img, const point_t *origin,
    size_t size, uint32_t color);

#endif /* !DRAWING_H_ */
