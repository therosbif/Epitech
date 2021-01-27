/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** make_key
*/

#include "proto.h"

double **make_key(char *str)
{
    double **key_matrix;

    matrix_size = (int) ceil(sqrt((double) strlen(str)));
    key_matrix = (double **) malloc(matrix_size * sizeof(double *));
    for (int i = 0; i < matrix_size; i++) {
        key_matrix[i] = malloc(matrix_size * sizeof(double));
        for (int j = 0; j < matrix_size; j++)
            key_matrix[i][j] = (*str) ? (double) *str++ : 0;
    }
    return (key_matrix);
}
