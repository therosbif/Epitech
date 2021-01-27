/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include "matchstick.h"

char **make_map(char **map, int lines)
{
    int width = lines * 2 + 1;
    int i = 1;

    for (int k = 0; k < width; map[0][k] = '*', k++);
    map[0][width] = 0;
    map[lines + 1] = my_strdup(map[0]);
    for (i = 1; i < lines + 1; i++) {
        map[i] = malloc(width + 2);
        map[i][0] = '*';
        map[i][width - 1] = '*';
        for (int j = 1; j < width - 1; j++) {
            if (j < width / 2 - i + 1 || j > width - 1 - (width / 2 - i + 1))
                map[i][j] = ' ';
            else
                map[i][j] = '|';
        }
        map[i][width] = 0;
    }
    map[i + 1] = 0;
    return map;
}

int *get_nb(int max, int *coords, char *line)
{
    char *buff = NULL;
    ssize_t len = 0;
    size_t nb = 0;
    int total = 0;

    for (int i = 1; line[i]; i++) total += (line[i] == '|');
    while (1) {
        my_putstr("Matches: ");
        free(buff);
        len = getline(&buff, &nb, stdin);
        if (len < 0 && (coords[0] = -2)) {
            free(buff);
            return coords;
        }
        if (my_isint(buff)) coords[1] = my_getnbr(buff);
        else coords[1] = -1;
        if (!nb_error(coords[1], total, max)) coords[1] = -1;
        free(buff);
        return coords;
    }
}

int row_err(int *coords, char *buff, int lines)
{
    if (coords[0] < 1 || coords[0] > lines || !my_isint(buff)) {
        my_putstr((my_isint(buff)) ? ERR_RANGE : ERR_INV);
        return 1;
    }
    return 0;
}

int *get_row(int lines, int max, int *coords, char **map)
{
    char *buff = NULL;
    ssize_t len = 0;
    size_t nb = 0;

    while (1) {
        my_putstr("Line: ");
        len = getline(&buff, &nb, stdin);
        if (len < 0 && (coords[0] = -2)) {
            free(buff);
            return coords;
        }
        coords[0] = my_getnbr(buff);
        if (row_err(coords, buff, lines)) continue;
        coords = get_nb(max, coords, map[coords[0]]);
        if (coords[1] == -1) continue;
        free(buff);
        if (coords[0] == -2) return coords;
        disp_pick(coords, 0);
        return coords;
    }
}

int game_loop(char **map, int lines, int max)
{
    int matches = lines * lines;
    int turn = 0;
    int *coords = malloc(sizeof(int) * 2);

    for (; matches && turn != -1; turn = !turn) {
        show_map(map, lines);
        my_putstr((turn) ? "\nAI's turn...\n" : "\nYour turn:\n");
        if (turn) {
            coords = pick_coords(max, coords, map);
            map = remove_matches(coords, map);
            matches -= coords[1];
        } else {
            coords = get_row(lines, max, coords, map);
            (coords[0] == -2) ? turn = -1 : 1;
            if (turn == -1) break;
            map = remove_matches(coords, map);
            matches -= coords[1];
        }
    }
    free(coords);
    return turn;
}
