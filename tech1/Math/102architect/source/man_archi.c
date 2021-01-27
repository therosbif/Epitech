/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** man_archi.c
*/

#include "102.h"

void man_archi(char **av)
{
    if (strlen(av[1]) == 2) {
        if (strcmp(av[1], "-h") == 0) {
            printf("USAGE\n");
            printf("    ./102architect x y transfo1 arg11 [arg12] "); 
            printf("[transfo2 arg12 [arg22]] ...\n\n");
            printf("DESCRIPTION\n");
            printf("    x   abscissa of the original point\n");
            printf("    y   ordinate of the original point\n\n");
            printf("    transfo arg1 [arg2]\n");
            printf("    -t i j  translation along vector (i, j)\n    -z m n");
            printf("  scaling by factors m (x-axis) and n (y-axis)\n");
            printf("    -r d    rotation centered in 0 by a d degree angle\n");
            printf("    -s d    reflection over the axis passing through 0");
            printf(" with an inclination angle of d degrees)\n");
            exit(0);
        }
    }
}

int my_is_float(char *str)
{
    for (; *str ; str++) {
        if ((*str < 48 || *str > 57) && *str != '.' && *str != '-')
            return 0;
    }
    return 1;
}

int my_is_flag(char *str)
{
    char *flags[5] = {"-t", "-z", "-r", "-s"};
    int j = 0;

    for (int i = 0 ; i < 4 ; i++) {
        if (!strcmp(str, flags[i]))
            j++;
    }
    return j;
}

int nb_args(int ac, char **av, int i)
{
    if (strcmp(av[i], "-t") == 0 || strcmp(av[i], "-z") == 0){
        if (!my_is_float(av[i + 1]) || !my_is_float(av[i + 2]))
            my_error();
        if (ac > i + 3)
            (!my_is_flag(av[i + 3])) ? my_error() : 1;
    } else {
        if (!my_is_float(av[i + 1]))
            my_error();
        if (ac > i + 2)
            (!my_is_flag(av[i + 2])) ? my_error() : 1;
    }
    return 1;
}