/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** display_encryption
*/

#include "proto.h"

void display_encryption(double **key_matrix, double **result_matrix)
{
    display_key_matrix_encryption(key_matrix);
    printf("Encrypted message:\n");
    for (int i = 0; i < matrix_height; i++) {
        for (int j = 0; j < matrix_size; j++) {
            if (i + 1 == matrix_height && j + 1 == matrix_size)
                printf("%d", (int) result_matrix[i][j]);
            else
                printf("%d ", (int) result_matrix[i][j]);
        }
    }
    printf("\n");
}
