/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** main
*/

#include <linux/input.h>
#include <linux/uinput.h>
#include <sys/fcntl.h>
#include <ncurses.h>
#include "tetris.h"
#include "term.h"
#include <stdio.h>
#include <sys/ioctl.h>

int main(int ac, char **av)
{
    settings_t *flags = getflags(ac, av);
    char key_pressed = 0;

    if (flags->debug) {
        debug_mode(flags);
        read(0, &key_pressed, 1);
    }
    tetris(flags);
    free(flags);
    return (0);
}
