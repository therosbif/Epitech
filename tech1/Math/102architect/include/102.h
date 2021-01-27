/*
** EPITECH PROJECT, 2019
** 102architect_2019
** File description:
** 102
*/

#ifndef HEAD_H_
#define HEAD_H_

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define  MY_ARGS    float *coords, char **av, float **mat, int i, int ac

void translate(float tx, float ty, float **mat);
void scale(float s1, float s2, float **mat);
void rotate(float r, float **mat);
void mirror(float a, float **mat);
int my_getnbr(char const *str);
int my_power_rec(int nb, int p);
void man_archi(char **av);
float **make_mat(void);
void my_error(void);
int nb_args(int ac, char **av, int i);
int my_is_flag(char *str);

#endif /* !HEAD_H_ */