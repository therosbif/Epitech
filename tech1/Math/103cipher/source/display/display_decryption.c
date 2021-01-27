/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** display_decryption
*/

#include "proto.h"

void display_decryption(double **decryption_matrix, double **result_matrix)
{
    display_key_matrix_decryption(decryption_matrix);
    printf("Decrypted message:\n");
    for (int i = 0; i < matrix_height; i++) {
        for (int j = 0; j < matrix_size; j++) {
            if ((int) round(result_matrix[i][j]))
                printf("%c", (int) round(result_matrix[i][j]));
        }
    }
    printf("\n");
}
