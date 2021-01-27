/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** display_key_matrix_encryption
*/

#include "proto.h"

void display_key_matrix_encryption(double **encryption_matrix)
{
    int j = 0;

    printf("Key matrix:\n");
    for (int i = 0; i < matrix_size; i++) {
        for (j = 0; j < matrix_size - 1; j++)
            printf("%-8d", (int) encryption_matrix[i][j]);
        printf("%d\n", (int) encryption_matrix[i][j]);
    }
    printf("\n");
}
