/*
** EPITECH PROJECT, 2019
** my
** File description:
** propotypes
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>

int my_power(int nb, int p);
int my_atoi(char const *str);
int my_isint(char *nb);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
void my_error(char *str);
int my_nlen(int n);
void print_lower_case(const char *str);
char *base_conv(long long nb, int base, char upper);

#endif /*MY_H_*/
