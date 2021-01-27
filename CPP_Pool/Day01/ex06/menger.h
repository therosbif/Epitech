/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD01-jack.goodall
** File description:
** menger
*/

#ifndef MENGER_H_
#define MENGER_H_

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include "drawing.h"

#define OFF unsigned int offx, unsigned int offy

int menger(int size, const int level, unsigned int offx,
    unsigned int offy, unsigned int **img);
void menger_face(const char *name, size_t size, int level);
int error_check(int ac, char const *av[]);
void create_bitmap_from_buffer(const char *name,
    size_t size, unsigned int *buffer);
void create_image(size_t size, unsigned int *buffer,
    unsigned int **img, int level);

#endif /* !MENGER_H_ */
