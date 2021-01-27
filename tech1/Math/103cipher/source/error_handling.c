/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** error_handling
*/

#include "proto.h"

__attribute__((constructor)) void error_handling(int argc, char **argv)
{
    if (argc == 2 && !strcmp(argv[1], "-h")) {
        write(1, USAGE, 233);
        exit(0);
    } else if (argc != 4) {
        write(2, "ERROR: Wrong number of args\n", 29);
        exit(84);
    }
    if (strcmp(argv[3], "0") && strcmp(argv[3], "1")) {
        write(2, "ERROR: Invalid flag\n", 21);
        exit(84);
    }
}
