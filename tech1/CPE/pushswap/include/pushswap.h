/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** pushswap
*/

#ifndef PUSHSWAP_H_
#define PUSHSWAP_H_

#include <stdlib.h>
#include <unistd.h>

typedef struct list {
    int data;
    struct list *next;
} list_t;

int my_atoi(char const *str);
int my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);

void print_step(list_t *l_a, list_t *l_b);
void free_list(list_t *l_a);

void sa(list_t **l_a, list_t **l_b, char *str);
void sb(list_t **l_a, list_t **l_b);
void sc(list_t **l_a, list_t **l_b);

void pa(list_t **l_a, list_t **l_b, char *str);
void pb(list_t **l_a, list_t **l_b);

void ra(list_t **l_a, list_t **l_b, char *str);
void rb(list_t **l_a, list_t **l_b);
void rr(list_t **l_a, list_t **l_b);

void rra(list_t **l_a, list_t **l_b);
void rrb(list_t **l_a, list_t **l_b);
void rrr(list_t **l_a, list_t **l_b);

int offset;
int flag;
char buff[1000000];

#define PRINT_STEP  (!flag) ? print_step(*l_a, *l_b) : 1

#define PRINT_BUFF                                                            \
if ((buff[offset - 3] == 'p' && *str == 'p' && buff[offset - 2] != str[1]) || \
(buff[offset - 3] == 's' && *str == 's' && buff[offset - 2] == str[1]))       \
    offset -= 3;                                                              \
else { \
    if (offset + 3 >= 1000000) { \
        write(1, buff, offset); \
        offset = 0; \
    } \
    for (; *str; buff[offset] = *str, offset++, str++); \
}

#endif /* !PUSHSWAP_H_ */

