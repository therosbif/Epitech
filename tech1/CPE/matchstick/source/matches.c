/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include "matchstick.h"

char **remove_matches(int *coords, char **map)
{
    int i = 0;

    for (; map[coords[0]][i] != '|'; i++);
    for (; map[coords[0]][i + 1] != ' ' && map[coords[0]][i + 1] != '*'; i++);
    for (int j = 0; j < coords[1]; j++, i--)
        map[coords[0]][i] = ' ';
    return map;
}

int cntmtch(char *line)
{
    int i = 0;

    for (; *line; i += (*line == '|'), line++);
    return i;
}

int *pick_coords(int max, int *coords, char **map)
{
    int i = 1;

    for (; map[i]; i++) {
        if (cntmtch(map[i]) > 1 && cntmtch(map[i]) - 1 <= max) {
            coords[0] = i;
            coords[1] = cntmtch(map[i]) - 1;
            break;
        }
    }
    if (!map[i]) {
        for (coords[0] = 0; !cntmtch(map[coords[0]]); coords[0]++);
        coords[1] = cntmtch(map[coords[0]]);
    }
    coords[1] = MIN(coords[1], max);
    disp_pick(coords, 1);
    return (coords);
}
