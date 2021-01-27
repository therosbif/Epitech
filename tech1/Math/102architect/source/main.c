/*
** EPITECH PROJECT, 2019
** 102architect_2019
** File description:
** main
*/

#include "102.h"

void my_error(void)
{
    write(2, "ERROR : Wrong number of args", 29);
    exit(84);
}

float **make_mat(void)
{
    float **mat = malloc(sizeof(float *) * 3);

    for (int i = 0; i < 3; i++) {
        mat[i] = malloc(sizeof(float) *  3);
        for (int j = 0; j < 3; j++) {
            mat[i][j] = 0;
        }
    }
    return mat;
}

float *calc_coords(float *coords, float **mat)
{
    float *dest = malloc(2);

    dest[0] = coords[0] * mat[0][0] + coords[1] * mat[0][1] + mat[0][2];
    dest[1] = coords[0] * mat[1][0] + coords[1] * mat[1][1] + mat[1][2];
    return dest;
}

float *test_flags(MY_ARGS)
{
    if (strcmp(av[i], "-t") == 0) {
        (ac <= i + 2) ? my_error() : nb_args(ac, av, i);
        translate(atof(av[i + 1]), atof(av[i + 2]), mat);
        coords = calc_coords(coords, mat);
    } if (strcmp(av[i], "-z") == 0) {
        (ac <= i + 2) ? my_error() : nb_args(ac, av, i);
        scale(atof(av[i + 1]), atof(av[i + 2]), mat);
        coords = calc_coords(coords, mat);
    } if (strcmp(av[i], "-r") == 0) {
        (ac <= i + 1) ? my_error() : nb_args(ac, av, i);
        rotate(atof(av[i + 1]), mat);
        coords = calc_coords(coords, mat);
    } if (strcmp(av[i], "-s") == 0) {
        (ac <= i + 1) ? my_error() : nb_args(ac, av, i);
        mirror(atof(av[i + 1]), mat);
        coords = calc_coords(coords, mat);
    }
    return coords;
}

int main(int ac, char **av)
{
    float **mat = make_mat();
    float *coords = malloc(sizeof(float) * 2);

    if (ac < 5)
        my_error();
    man_archi(av);
    coords[0] = atof(av[1]);
    coords[1] = atof(av[2]);
    for (int i = 0 ; i < ac ; i++) {
        coords = test_flags(coords, av, mat, i, ac);
    }
    printf("%-8.2f%-8.2f%.2f\n", mat[0][0], mat[0][1], mat[0][2]);
    printf("%-8.2f%-8.2f%.2f\n", mat[1][0], mat[1][1], mat[1][2]);
    printf("%-8.2f%-8.2f%.2f\n", mat[2][0], mat[2][1], mat[2][2]);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n",atof(av[1]),
    atof(av[2]), coords[0], coords[1]);
    return 0;
}