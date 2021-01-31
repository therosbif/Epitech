/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** measure
*/

#include <sokoban.h>

pos_t init_pos(char *map)
{
    pos_t pos = {0, 0};

    for (; *map != 'P'; map++) {
        if (*map == '\n') {
            pos.x = -1;
            pos.y++;
        } else
            pos.x++;
    }
    pos.x++;
    return (pos);
}

void map_error(char *map)
{
    for (int i = 0; map[i]; i++) {
        if (!(map[i] == '#' || map[i] == '\n' || map[i] == 'X' || map[i] == 'O'
        || map[i] == 'P' || map[i] == ' '))
            exit(84);
    }
}

char *get_map(int ac, char **av)
{
    char *buff = malloc(400);
    int fd = 0;
    int len = 0;

    (ac < 2) ? exit(84) : 1;
    if (!my_strcmp(av[1], "-h")) {
        write(1, "USAGE\n    ./my_sokoban map\n", 28);
        write(1, "DESCRIPTION\n", 13);
        write(1, "    map  file representing the warehouse map, ", 47);
        write(1, "containing ‘#’ for walls, \n", 31);
        write(1, "         ‘P’ for the player, ‘X’ for boxes and ‘O’ ", 63);
        write(1, "for storage locations.", 23);
        exit(0);
    }
    fd = open(av[1], O_RDONLY);
    (fd < 0) ? exit(84) : 1;
    len = read(fd, buff, 400);
    buff[len] = '\0';
    close(fd);
    return buff;
}

pos_t get_dim(char *map)
{
    int x = 0;
    pos_t dim = {0, 0};

    for (int i = 0; map[i]; i++) {
        x++;
        if (map[i] == '\n') {
            dim.y++;
            dim.x = (x > dim.x) ? x : dim.x;
            x = 0;
        }
    }
    dim.y++;
    return (dim);
}

void resize_msg(pos_t max, char *map)
{
    clear();
    mvprintw(max.y / 2, max.x / 2, "ERROR :\nWINDOW TOO SMALL");
    refresh();
    clear();
    printw(map);
}
