/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** make_message
*/

#include "proto.h"

int **make_message(char *str, int decription)
{
    int **message_matrix;

    matrix_height = (int) ceil((double) strlen(str) / (double) matrix_size);
    message_matrix = (int **) malloc(sizeof(int *) * matrix_height);
    str = (decription) ? strtok(str, " ") : str;
    if (decription) {
        for (int i = 0; i < matrix_height; i++) {
            message_matrix[i] = (int *) malloc(sizeof(int) * matrix_size);
            for (int j = 0; j < matrix_size; j++) {
                message_matrix[i][j] = (str) ? (int) strtol(str, NULL, 10) : 0;
                (str) ? str = strtok(NULL, " ") : 0;
            }
        }
    } else {
        for (int i = 0; i < matrix_height; i++) {
            message_matrix[i] = (int *) malloc(sizeof(int) * matrix_size);
            for (int j = 0; j < matrix_size; j++)
                message_matrix[i][j] = (*str) ? (int) *str++ : 0;
        }
    }
    return message_matrix;
}
