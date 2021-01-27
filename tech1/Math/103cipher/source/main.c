/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** main
*/

#include "proto.h"

int main(__attribute__((unused)) int argc, char **argv)
{
    double **key_matrix = make_key(argv[2]);
    int **message_matrix = make_message(argv[1], atoi(argv[3]));
    double **res_matrix;
    double **decription_matrix;

    if (!atoi(argv[3])) {
        res_matrix = make_result(message_matrix, key_matrix);
        display_encryption(key_matrix, res_matrix);
    } else {
        decription_matrix = make_inverse(key_matrix);
        res_matrix = make_result(message_matrix, decription_matrix);
        display_decryption(decription_matrix, res_matrix);
    }
    return 0;
}
