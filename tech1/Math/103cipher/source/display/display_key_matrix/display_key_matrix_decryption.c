/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** display_key_matrix_decription
*/

#include "proto.h"

void display_key_matrix_decryption(double **decryption_matrix)
{
    int j = 0;

    printf("Key matrix:\n");
    for (int i = 0; i < matrix_size; i++) {
        for (j = 0; j < matrix_size - 1; j++)
            if (decryption_matrix[i][j])
                printf("%-8.3f", decryption_matrix[i][j]);
            else
                printf("%-8.1f", decryption_matrix[i][j]);
        printf("%.3f\n", decryption_matrix[i][j]);
    }
    printf("\n");
}
