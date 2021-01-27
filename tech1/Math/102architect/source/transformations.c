/*
** EPITECH PROJECT, 2019
** 102architect_2019
** File description:
** transformations
*/

#include "102.h"

void translate(float tx, float ty, float **mat)
{
    printf("Translation along vector (%.0f, %.0f)\n", tx, ty);
    mat[0][0] += 1;
    mat[1][1] += 1;
    mat[2][2] += 1;
    mat[0][2] += tx;
    mat[1][2] += ty;
}

void scale(float s1, float s2, float **mat)
{
    printf("Scaling by factors %.0f and %.0f\n", s1, s2);
    mat[0][0] += s1;
    mat[1][1] += s2;
    mat[2][2] += 1;
}

void rotate(float r, float **mat)
{
    printf("Rotation by a %.0f degree angle\n", r);
    mat[0][0] += cos(r * 3.1415 / 180);
    mat[0][1] += -sin(r * 3.1415 / 180);
    mat[1][0] += sin(r * 3.1415 / 180);
    mat[1][1] += cos(r * 3.1415 / 180);
    mat[2][2] += 1;
}

void mirror(float a, float **mat)
{
    printf("Reflection over an axis with an ");
    printf("inclination angle of %.0f degrees\n", a);
    mat[0][0] += cos(2 * (a * 3.1415 / 180));
    mat[0][1] += sin(2 * (a * 3.1415 / 180));
    mat[1][0] += sin(2 * (a * 3.1415 / 180));
    mat[1][1] += -cos(2 * (a * 3.1415 / 180));
    mat[2][2] += 1;
}