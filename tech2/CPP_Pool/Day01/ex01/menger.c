/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD01-jack.goodall
** File description:
** menger
*/

#include <stdio.h>

int menger(int size, int levels, int offx, int offy)
{
    int sq_size = size / 3;
    int sq_x = size / 3 + offx;
    int sq_y = size / 3 + offy;

    printf("%03d %03d %03d\n", sq_size, sq_x, sq_y);
    for (int x = 0; x < size; x += size / 3) {
        for (int y = 0; y < size; y += size / 3) {
            if ((x + offx != sq_x || y + offy != sq_y)
                && size > 1 && levels > 1)
                menger(size / 3, levels - 1, x + offx, y + offy);
        }
    }
    return 0;
}
