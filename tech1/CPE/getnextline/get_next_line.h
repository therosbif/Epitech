/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** get_next_line
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef READ_SIZE
#define READ_SIZE (10)
#endif

#define STRCAT \
int j = my_strlen(*file); \
int i = my_strlen(buff); \
char *final = malloc(i + j + 1); \
my_strcpy(final, *file); \
my_strcpy(final + j, buff); \
free(*file); \
*file = final;

int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *get_next_line(int fd);

#endif /* !GET_NEXT_LINE_H_ */
