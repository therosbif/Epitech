/*
** EPITECH PROJECT, 2019
** fractals.h
** File description:
** main
*/

#ifndef FRACTALS_H_
#define FRACTALS_H_

#include <stdlib.h>
#include <unistd.h>

typedef struct masks {
    char **mask;
    char **mask_empty;
} mask_t;

char **create_shape(char *str);
int is_int(char *str);
int my_error(int ac, char **av);
int my_atoi(char *str);
int is_valid_chars(char *str);
int my_strlen(char *str);
int my_strlen_delim(char *str, char delim);
int my_putchar(char c);
int count_char_instr(char *str, char c);
void free_arr(char **arr);
int my_arrlen(char **arr);
void copy_over(char **shape, char ***new_shape, int x, int y);
void empty_shape(char **shape, char ***new_shape, int x, int y);
int my_putstr(char const *str);
char **fractals(char **shape, char **shape_empty, mask_t masks, int i);

#endif
