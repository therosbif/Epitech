/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD01-jack.goodall
** File description:
** menger
*/

#include <stdio.h>
#include "menger.h"
#include "drawing.h"

uint32_t get_hex(const int level)
{
    const uint32_t value = (0xFF / level);

    return (value * 0x10000 + value * 0x100 + value);
}

int menger(int size, const int level, OFF, unsigned int **img)
{
    unsigned int sq_size = size / 3;
    point_t sq_coord = { size / 3 + offx, size / 3 + offy };

    draw_square(img, &sq_coord, sq_size, get_hex(level));
    for (int x = 0; x < size; x += size / 3) {
        for (int y = 0; y < size; y += size / 3) {
            if ((x + offx != sq_coord.x || y + offy != sq_coord.y)
                && size > 1 && level > 1) {
                menger(size / 3, level - 1, offx + x, offy + y, img);
            }
        }
    }
    return 0;
}

void menger_face(const char *name, size_t size, const int level)
{
    unsigned int *buffer = malloc(size * size * sizeof(*buffer));
    unsigned int **img = malloc(size * sizeof(*img));

    create_image(size, buffer, img, level);
    create_bitmap_from_buffer(name, size, buffer);
}

int error_check(int ac, char const *av[])
{
    if (ac != 4) {
        write(2, "menger_face file_name size level\n", 34);
        return 1;
    } if (atoi(av[3]) < 1)
        return 2;
    if (atoi(av[2]) < 1 || atoi(av[2]) % (int)pow(3, atoi(av[3])))
        return 3;
    return 0;
}
