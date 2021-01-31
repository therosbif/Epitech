/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <fcntl.h>

typedef struct flags {
    int l;
    int r;
    int d;
    int t;
    int _r;
    int a;
    int total;
} flags_t;

int my_ls(char **av, char *path);
flags_t *set_flags(char **av);
flags_t *init_flags(void);
int my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_strcat(char *dest, char const *src, int slash);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char **str_to_array(char **dest, char *src);
int my_strcmp(char const *s1, char const *s2);
char **sort_array(char **src, flags_t *flags, char *path, char *tmp);
int my_show_word_array(char * const *tab, flags_t *flags, char **av,
char *path);
char *my_low(char *str);
void l_prefix(char *file, char *path);
int my_ac(int i);

#endif
