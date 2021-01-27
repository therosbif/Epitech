/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD01-jack.goodall
** File description:
** pyramid
*/

#include <stdio.h>

int pyramid_rec(const int size, const int **map, int x, int y)
{
    int total = map[y][x];
    int a;
    int b;

    if (y + 1 < size) {
        a = pyramid_rec(size, map, x, y + 1);
        b = pyramid_rec(size, map, x + 1, y + 1);
        total += (a < b) ? a : b;
    }
    return total;
}

int pyramid_path(int size, const int **map)
{
    return pyramid_rec(size, map, 0, 0);
}
