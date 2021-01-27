/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** make_inverse
*/

#include "proto.h"

double **make_inverse(double **key_matrix)
{
    double **inv_matrix = malloc(matrix_size * sizeof(int *));

    for (int i = 0; i < matrix_size; i++)
        inv_matrix[i] = malloc(matrix_size * sizeof(int));
    if (matrix_size == 1)
        inv_matrix[0][0] = 1 / A_;
    else if (matrix_size == 2) {
        inv_matrix[0][0] = DETERMINANT2 * E_;
        inv_matrix[0][1] = DETERMINANT2 * (-(B_));
        inv_matrix[1][0] = DETERMINANT2 * (-(D_));
        inv_matrix[1][1] = DETERMINANT2 * A_;
    } else if (matrix_size == 3) {
        CALC_INV;
    }
    return inv_matrix;
}
