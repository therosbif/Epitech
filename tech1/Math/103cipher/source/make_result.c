/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** make_result
*/

#include "proto.h"

double **make_result(int **message_matrix, double **key_matrix)
{
    double **result_matrix = malloc(matrix_height * sizeof(double *));

    for (int i = 0; i < matrix_height; i++) {
        result_matrix[i] = malloc(matrix_size * sizeof(double));
        for (int j = 0; j < matrix_size; j++) {
            result_matrix[i][j] = 0;
            for (int k = 0; k < matrix_size; k++)
                result_matrix[i][j] += message_matrix[i][k] * key_matrix[k][j];
        }
    }
    return (result_matrix);
}
