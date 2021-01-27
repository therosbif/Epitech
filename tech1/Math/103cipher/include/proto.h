/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** proto
*/

#ifndef PROTO_H_
#define PROTO_H_

#include "unistd.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"


int matrix_size;
int matrix_height;

#define A_ key_matrix[0][0]
#define B_ key_matrix[0][1]
#define C_ key_matrix[0][2]
#define D_ key_matrix[1][0]
#define E_ key_matrix[1][1]
#define F_ key_matrix[1][2]
#define G_ key_matrix[2][0]
#define H_ key_matrix[2][1]
#define I_ key_matrix[2][2]

#define DETERMINANT2    \
1 / (A_ * E_ - D_ * B_)

#define DETERMINANT3    \
1 / (                   \
A_ * E_ * I_ +          \
B_ * F_ * G_ +          \
C_ * D_ * H_ -          \
C_ * E_ * G_ -          \
F_ * H_ * A_ -          \
I_ * B_ * D_)

#define CALC_INV                                       \
inv_matrix[0][0] = DETERMINANT3 * (E_ * I_ - F_ * H_); \
inv_matrix[0][1] = DETERMINANT3 * (C_ * H_ - B_ * I_); \
inv_matrix[0][2] = DETERMINANT3 * (B_ * F_ - C_ * E_); \
inv_matrix[1][0] = DETERMINANT3 * (F_ * G_ - D_ * I_); \
inv_matrix[1][1] = DETERMINANT3 * (A_ * I_ - C_ * G_); \
inv_matrix[1][2] = DETERMINANT3 * (C_ * D_ - A_ * F_); \
inv_matrix[2][0] = DETERMINANT3 * (D_ * H_ - E_ * G_); \
inv_matrix[2][1] = DETERMINANT3 * (B_ * G_ - A_ * H_); \
inv_matrix[2][2] = DETERMINANT3 * (A_ * E_ - B_ * D_)

#define USAGE \
"USAGE\n\
    ./103cipher message key fla\n\
DESCRIPTION\n\
    message     a message, made of ASCII characters\n\
    key         the encryption key, made of ASCII characters\n\
    flag        0 for the message to be encrypted, 1 to be decrypted\n"

double **make_key(char *str);
int **make_message(char *str, int decription);
double **make_result(int **message_matrix, double **key_matrix);
double **make_inverse(double **key_matrix);

void display_encryption(double **key_matrix, double **result_matrix);
void display_decryption(double **decription_matrix, double **result_matrix);
void display_key_matrix_decryption(double **decryption_matrix);
void display_key_matrix_encryption(double **encryption_matrix);

#endif /* !PROTO_H_ */
